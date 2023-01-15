#include "con.h"
void iline(int cx0, int cy0, int cx1, int cy1) {
  int maxp, tt;
  char chx, chy, command;
  float xd, yd;
  float dist2();
  movep(cx0, cy0);
  maxp = sqrt(dist2(cx0, cy0, cx1, cy1)) / 2.;
  xd = cx1 - cx0;
  yd = cy1 - cy0;
  command = COM | ((xd < 0) << 1) | (yd < 0);
  if (maxp == 0) {
    xd = 0;
    yd = 0;
  } else {
    xd /= maxp;
    yd /= maxp;
  }
  inplot();
  spew(command);
  for (tt = 0; tt <= maxp; tt++) {
    chx = cx0 + xd * tt - xnow;
    xnow += chx;
    chx = abval(chx);
    chy = cy0 + yd * tt - ynow;
    ynow += chy;
    chy = abval(chy);
    spew(ADDR | chx << 3 | chy);
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
