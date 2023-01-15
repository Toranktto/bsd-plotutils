#include "hp2648.h"

void pl_circle(int xc, int yc, int r) {
  double costheta, sintheta, x, y, xn;
  int xi, yi;

  if (r < 1) {
    pl_point(xc, yc);
    return;
  }
  sintheta = 1.0 / r;
  costheta = pow(1 - sintheta * sintheta, 0.5);
  xi = x = r;
  yi = y = 0;
  do {
    pl_point(xc + xi, yc + yi);
    xn = x;
    xi = x = x * costheta + y * sintheta;
    yi = y = y * costheta - xn * sintheta;
  } while (!(yi == 0 && xi >= r - 1));
}
