#include "con.h"

int xconv(int xp) {
  /* x position input is -2047 to +2047, output must be 0 to PAGSIZ*HORZRES */
  xp += 2048;
  /* the computation is newx = xp*(PAGSIZ*HORZRES)/4096 */
  return (xoffset + xp / xscale);
}

int yconv(int yp) {
  /* see description of xconv */
  yp += 2048;
  return (yp / yscale);
}

void spew(int ch) { putc(ch, stdout); }

void inplot(void) {
  stty(OUTF, &PTTY);
  spew(ESC);
  spew(INPLOT);
}

void outplot(void) {
  spew(ESC);
  spew(ACK);
  spew(ESC);
  spew(ACK);
  fflush(stdout);
  stty(OUTF, &ITTY);
}

void tobotleft(void) { pl_move(-2048, -2048); }

void reset(void) {
  outplot();
  exit(1);
}

float dist2(int x1, int y1, int x2, int y2) {
  float t, v;
  t = x2 - x1;
  v = y1 - y2;
  return (t * t + v * v);
}

void swap(int *pa, int *pb) {
  int t;
  t = *pa;
  *pa = *pb;
  *pb = t;
}

#define DOUBLE 010
#define ADDR 0100
#define COM 060
#define MAXX 070
#define MAXY 07
extern int xnow, ynow;
#define SPACES 7

void movep(int ix, int iy) {
  int dx, dy, remx, remy, pts, i;
  int xd, yd;
  int addr, command;
  char c;
  if (xnow == ix && ynow == iy)
    return;
  inplot();
  dx = ix - xnow;
  dy = iy - ynow;
  command = COM | PENUP | ((dx < 0) << 1) | (dy < 0);
  dx = abs(dx);
  dy = abs(dy);
  xd = dx / (SPACES * 2);
  yd = dy / (SPACES * 2);
  pts = xd < yd ? xd : yd;
  if ((i = pts) > 0) {
    c = command | DOUBLE;
    addr = ADDR;
    if (xd > 0)
      addr |= MAXX;
    if (yd > 0)
      addr |= MAXY;
    spew(c);
    while (i--) {
      spew(addr);
    }
  }
  if (xd != yd) {
    if (xd > pts) {
      i = xd - pts;
      addr = ADDR | MAXX;
    } else {
      i = yd - pts;
      addr = ADDR | MAXY;
    }
    c = command | DOUBLE;
    spew(c);
    while (i--) {
      spew(addr);
    }
  }
  remx = dx - xd * SPACES * 2;
  remy = dy - yd * SPACES * 2;
  addr = ADDR;
  i = 0;
  if (remx > 7) {
    i = 1;
    addr |= MAXX;
    remx -= 7;
  }
  if (remy > 7) {
    i = 1;
    addr |= MAXY;
    remy -= 7;
  }
  while (i--) {
    spew(command);
    spew(addr);
  }
  if (remx > 0 || remy > 0) {
    spew(command);
    spew(ADDR | remx << 3 | remy);
  }
  xnow = ix;
  ynow = iy;
  outplot();
  return;
}

int xsc(int xi) {
  int xa;
  xa = (xi - obotx) * scalex + botx;
  return (xa);
}

int ysc(int yi) {
  int ya;
  ya = (yi - oboty) * scaley + boty;
  return (ya);
}
