#include "hp2648.h"

void pl_arc(int xcent, int ycent, int xbeg, int ybeg, int xend, int yend) {
  double costheta, sintheta, x, y, xn, r;
  double x1, y1, x2, y2;
  int xi, yi, crosspflag, crossp;

  r = (xcent - xbeg) * (xcent - xbeg) + (ycent - ybeg) * (ycent - ybeg);
  r = pow(r, 0.5);
  if (r < 1) {
    pl_point(xcent, ycent);
    return;
  }
  sintheta = 1.0 / r;
  costheta = pow(1 - sintheta * sintheta, 0.5);
  xi = x = xbeg - xcent;
  yi = y = ybeg - ycent;
  x1 = xcent;
  y1 = ycent;
  x2 = xend;
  y2 = yend;
  crosspflag = 0;
  do {
    crossp = cross_product(x1, y1, x2, y2, x, y);
    if (crossp > 0 && crosspflag == 0)
      crosspflag = 1;
    pl_point(xcent + xi, ycent + yi);
    xn = x;
    xi = x = x * costheta + y * sintheta;
    yi = y = y * costheta - xn * sintheta;
  } while (crosspflag == 0 || crossp > 0);
}

int cross_product(double x1, double y1, double x2, double y2, double x3,
                  double y3) {
  double z, a, b;
  a = (y3 - y2) * (x2 - x1);
  b = (x3 - x2) * (y2 - y1);
  z = a - b;
  if (z < 0)
    return (-1);
  if (z > 0)
    return (1);
  return (0);
}
