#include "hp7221.h"

void pl_circle(int xc, int yc, int r) {
  if (r < 1) {
    pl_point(xc, yc);
    return;
  }
  pl_move(xc, yc);
  putchar('t');
  putMBN(scaleX(r));
}
