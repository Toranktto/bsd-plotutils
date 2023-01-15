#include "gigi.h"

pl_space(x0, y0, x1, y1) int x0, y0, x1, y1;
{
  lowx = x0;
  lowy = y0;
  scalex = XMAX / (x1 - lowx);
  scaley = YMAX / (y1 - lowy);
}
