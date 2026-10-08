// The Gled talk at the ALICE Offline weekly meeting, 7 October 2004, as a
// slide show in an amphitheatre. The pages are in pages/.
//
// vars: ZQueen* g_queen
// libs: Geom1

#include <glass_defines.h>
#include <gl_defines.h>

#include "sun_demos.C"
#include "eye.C"

#pragma cling load("libGeom1.so")

using namespace gled;

MultiBoard* gled_talk(ZList* list);
void        demo_amphitheatre(Amphitheatre* amph);

/**************************************************************************/
// main
/**************************************************************************/

void slides(Bool_t start_hunt_p=true)
{
  ASSERT_MACRO(sun_demos);
  Gled::theOne->AssertLibSet("Geom1");

  CREATE_ADD_GLASS(ss, Scene, g_queen, "Slide Scene", "Gled talk");
  g_scene = ss;

  // Basic scene elements
  //----------------------

  CREATE_ADD_GLASS(cam_base, Sphere, ss, "CameraBase", 0);
  cam_base->SetPos(5, -5, 4);
  cam_base->SetRotByDegrees(140, -26, 0);
  cam_base->SetRadius(0.01);

  CREATE_ADD_GLASS(l, Lamp, ss, "Lamp", 0);
  l->SetLampScale(1);
  l->SetPos(-4, -3, 10);
  l->SetAmbient(0.4, 0.4, 0.4);
  ss->GetGlobLamps()->Add(l);

  //--------------------------------

  CREATE_ADD_GLASS(blend, ZGlBlending, ss, "Line Smoothing", 0);
  blend->SetBlendOp(ZRnrModBase::O_On);
  blend->SetAntiAliasOp(ZRnrModBase::O_On);
  blend->SetLineWidth(1);
  blend->SetPointSize(16);

  CREATE_ADD_GLASS(plane_xy, Rect, ss, "Plane XY", 0);
  plane_xy->SetUnitSquare(20);
  plane_xy->SetColor(0,0,1,0.5);
  plane_xy->SetPos(0,0,-0.05);
  plane_xy->SetRotByDegrees(0,0,0);
  plane_xy->SetWidth(1);

  //--------------------------------

  CREATE_ADD_GLASS(amph, Amphitheatre, ss, "Amphitheatre", 0);
  demo_amphitheatre(amph);

  MultiBoard* talk = gled_talk(ss);
  talk->SetPos(-2, 0, 2.2);
  talk->SetUV(6, 4.5);
  talk->SetRotByDegrees(90, 0, 90);
  talk->First();

  /**************************************************************************/
  // Spawn the eye
  /**************************************************************************/

  eye();

  g_pupil->SetZFov(90);
  g_pupil->SetWidth(1024);
  g_pupil->SetHeight(600);
  g_pupil->SetClearColor(0.06, 0.07, 0.06);

  g_pupil->SetCameraBase(cam_base);
  g_pupil->SetUpReference(ss);

  CREATE_ADD_GLASS(etor, Eventor, ss, "Movie Maker", 0);
  etor->SetBeatsToDo(-1);
  etor->SetInterBeatMS(400); etor->SetStampInterval(10);
  CREATE_ADD_GLASS(sdumper, ScreenDumper, etor, "DumpRayEmitter", 0);
  sdumper->SetPupil(g_pupil);
  // sdumper->SetFileNameFmt("someplace/img%05d.tga");

  if (start_hunt_p) {
    gSystem->Sleep(1000);
    amph->StartHunt();
  }
}

/**************************************************************************/
// Scene elements
/**************************************************************************/

MultiBoard* gled_talk(ZList* list)
{
  printf("Loading the ALICE Offline Gled talk ...\n");
  CREATE_ADD_GLASS(multiboard, MultiBoard, list, "Gled Talk", 0);
  for (int i=0; i<10; i++) {
    ZImage* img = new ZImage(GForm("Page %d", i));
    img->SetFile(GForm("pages/page.%d.png", i));
    img->SetMagFilter(GL_LINEAR);
    img->SetMinFilter(GL_LINEAR);
    img->Load();
    img->SetLoadAdEnlight(true);
    g_queen->CheckIn(img);
    multiboard->GetSlides()->Add(img);
  }

  CREATE_ADD_GLASS(talkview, Sphere, multiboard, "Talk Viewpoint", 0);
  talkview->SetRotByDegrees(90, -90, 0);
  talkview->MoveLF(1, -4.5/2);
  talkview->SetRadius(0.01);

  return multiboard;
}

/**************************************************************************/

void demo_amphitheatre(Amphitheatre* amph)
{
  amph->SetGuestStep(0.05);
  amph->SetStepSleepMS(50);

  amph->CreateChairs(6, 0, 2,    90, 26);
  amph->CreateChairs(5, 0, 1,    90, 20);
  amph->CreateChairs(4, 0, 0.5,  90, 16);
  amph->CreateChairs(3, 0, 0.25, 90, 12);
  amph->CreateChairs(2, 0, 0,    90, 8);

  CREATE_ADD_GLASS(occ1, Sphere, amph, "A Big Guest", 0);
  occ1->SetRadius(0.2);
  occ1->SetPos(0, 0.25, 0);
  occ1->SetColor(0, 0, 1);
  amph->AddGuest(occ1);
  CREATE_ADD_GLASS(occ2, Sphere, amph, "Big Guest's Wife", 0);
  occ2->SetRadius(0.25);
  occ2->SetPos(0, -0.25, 0);
  occ2->SetColor(1, 0, 0);
  amph->AddGuest(occ2);

  amph->MakeRandomGuests(80, 5);
}
