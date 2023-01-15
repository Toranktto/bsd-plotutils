#include "hp7221.h"

pl_space(x0, y0, x1, y1) int x0, y0, x1, y1;
{
  double scalex, scaley;
  lowx = x0;
  lowy = y0;
  scalex = XMAX / (double)(x1 - lowx);
  scaley = YMAX / (double)(y1 - lowy);
  scale = scalex < scaley ? scalex : scaley;
}
