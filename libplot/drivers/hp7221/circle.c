#include "hp7221.h"

pl_circle(xc, yc, r) int xc, yc, r;
{
  if (r < 1) {
    pl_point(xc, yc);
    return;
  }
  pl_move(xc, yc);
  putchar('t');
  putMBN(scaleX(r));
}
