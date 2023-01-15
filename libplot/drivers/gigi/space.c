#include "gigi.h"

void pl_space(int x0, int y0, int x1, int y1) {
  lowx = x0;
  lowy = y0;
  scalex = XMAX / (x1 - lowx);
  scaley = YMAX / (y1 - lowy);
}
