#include "gigi.h"

pl_circle(xc, yc, r) int xc, yc, r;
{
  if (r < 1) {
    pl_point(xc, yc);
    return;
  }
  pl_move(xc, yc);
  printf("C[%d]", r);
}
