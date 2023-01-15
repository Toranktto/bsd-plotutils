#include "hp2648.h"

pl_space(x0, y0, x1, y1) int x0, y0, x1, y1;
{
  lowx = x0;
  lowy = y0;
  scalex = 720.0 / (x1 - lowx);
  scaley = 360.0 / (y1 - lowy);
}
