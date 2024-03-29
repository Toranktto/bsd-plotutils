#include "con.h"

void iline(int cx0, int cy0, int cx1, int cy1) {
  int maxp, tt, j;
  char chx, chy;
  float xd, yd;

  movep(cx0, cy0);
  maxp = sqrt(dist2(cx0, cy0, cx1, cy1)) / 2.;
  xd = cx1 - cx0;
  yd = cy1 - cy0;
  if (xd >= 0)
    chx = RIGHT;
  else
    chx = LEFT;
  if (yd >= 0)
    chy = UP;
  else
    chy = DOWN;
  if (maxp == 0) {
    xd = 0;
    yd = 0;
  } else {
    xd /= maxp;
    yd /= maxp;
  }
  inplot();
  for (tt = 0; tt <= maxp; tt++) {
    j = cx0 + xd * tt - xnow;
    xnow += j;
    j = abs(j);
    while (j-- > 0)
      spew(chx);
    j = cy0 + yd * tt - ynow;
    ynow += j;
    j = abs(j);
    while (j-- > 0)
      spew(chy);
    spew('.');
  }
  outplot();
  return;
}

void pl_line(int x0, int y0, int x1, int y1) {
  iline(xconv(xsc(x0)), yconv(ysc(y0)), xconv(xsc(x1)), yconv(ysc(y1)));
  return;
}

void pl_cont(int x0, int y0) {
  iline(xnow, ynow, xconv(xsc(x0)), yconv(ysc(y0)));
  return;
}
