#include "vt0.h"

void pl_dot(int xi, int yi, int dx, int n, int pat[]) {
  struct {
    char pad, c;
    int xi, yi, dx;
  } p;
  p.c = 7;
  p.xi = xsc(xi);
  p.yi = ysc(yi);
  p.dx = xsc(dx);
  write(vti, &p.c, 7);
  write(vti, pat, n ? n & 0377 : 256);
}
