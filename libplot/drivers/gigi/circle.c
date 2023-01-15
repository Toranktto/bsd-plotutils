#include "gigi.h"

void pl_circle(int xc, int yc, int r) {
  if (r < 1) {
    pl_point(xc, yc);
    return;
  }
  pl_move(xc, yc);
  printf("C[%d]", r);
}
