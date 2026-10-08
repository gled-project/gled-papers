# Gled papers

Papers and talks about [Gled](https://github.com/gled-project/gled), as
LaTeX sources with their figures.

| path | what |
|---|---|
| `gled-ihscm/` | *GLED – an Implementation of a Hierarchic Server–Client Model*, the core of Gled and the ideas of its implementation; the author's submitted version of a book chapter, see its README |
| `gled-auth/` | *Authentication & Authorization Infrastructure of Gled*, implementation details of authentication and authorization; not published elsewhere |
| `talks/2004-10-07-alice-offline-gm/` | the first talk about Gled, at the ALICE Offline weekly meeting on 7 October 2004, with the slide show that runs in Gled |

Each directory has a Makefile that runs `latex` and `dvips`, and for the
papers also `pdflatex`. They need the `fullpage` and `wrapfig` packages
and, for `gled-ihscm-1.2.0.tex`, the SIAM class `siamltex`.

## License

gled-auth and the talk, text, figures and page images, are under the
Creative Commons Attribution 4.0 International license,
`LICENSE-CC-BY-4.0.txt`. The talk's `slides.C` is under the GNU Lesser
General Public License, version 3 or later, `COPYING.LESSER` with
`COPYING`. gled-ihscm is not under either license; see
`gled-ihscm/README.md`.
