# Gled at the ALICE Offline weekly meeting, 7 October 2004

The first talk about Gled, given by Matevž Tadel at the ALICE Offline
weekly meeting, the ALICE software general meeting, on 7 October 2004.
René Brun, Fons Rademakers and Federico Carminati were in the room.

The talk was given as a slide show inside Gled: the pages were one board in
a 3D scene, and at the end the view zoomed out into the scene. `slides.C`,
from 2008, builds such a scene: the board with the pages in front of an
amphitheatre whose guests hunt for chairs.

- `slides.tex` with `king-queens.*` and `eventor_mtw.*`: the LaTeX source
  of the slides.
- `pages/page.0.png` ... `page.9.png`: the ten pages rendered for Gled.
- `slides.C`: the scene. Run it from this directory with a Gled build that
  has the Geom1 libset:

  ```sh
  gled slides.C
  ```

  The board pages through the talk; `slides(false)` starts without the
  chair hunt.
