#include "con.h"

float deltx = 4095.;
float delty = 4095.;

void pl_space(int x0, int y0, int x1, int y1) {
  botx = -2047.;
  boty = -2047.;
  obotx = x0;
  oboty = y0;
  scalex = deltx / (x1 - x0);
  scaley = delty / (y1 - y0);
}
