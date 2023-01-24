#include "vt0.h"

void pl_line(int x0, int y0, int x1, int y1) {
  struct {
    char x, c;
    int x0, y0, x1, y1;
  } p;
  p.c = 3;
  p.x0 = xsc(x0);
  p.y0 = ysc(y0);
  p.x1 = xnow = xsc(x1);
  p.y1 = ynow = ysc(y1);
  write(vti, &p.c, 9);
}
void pl_cont(int x0, int y0) {
  pl_line(xnow, ynow, xsc(x0), ysc(y0));
  return;
}
