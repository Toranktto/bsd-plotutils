#include "hp2648.h"

void pl_space(int x0, int y0, int x1, int y1) {
  lowx = x0;
  lowy = y0;
  scalex = 720.0 / (x1 - lowx);
  scaley = 360.0 / (y1 - lowy);
}
