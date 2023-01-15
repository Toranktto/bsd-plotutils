#include "bg.h"

void pl_space(int x0, int y0, int x1, int y1) {
  double scalex, scaley;
  lowx = x0;
  lowy = y0;
  scalex = XMAX / (double)(x1 - lowx);
  scaley = YMAX / (double)(y1 - lowy);
  scale = scalex < scaley ? scalex : scaley;
}
