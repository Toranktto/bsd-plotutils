#include "con.h"

void pl_space(int x0, int y0, int x1, int y1) {
  botx = -2047.;
  boty = -2047.;
  obotx = x0;
  oboty = y0;
  scalex = 4096. / (x1 - x0);
  scaley = 4096. / (y1 - y0);
}
