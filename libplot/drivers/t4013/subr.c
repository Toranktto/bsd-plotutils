#include "t4013.h"

float obotx = 0.;
float oboty = 0.;
float botx = 0.;
float boty = 0.;
float scalex = 1.;
float scaley = 1.;
int scaleflag;

int oloy = -1;
int ohiy = -1;
int ohix = -1;

void putch(int c) { putc(c, stdout); }

void pl_cont(int x, int y) {
  int hix, hiy, lox, loy;
  int n;
  x = (x - obotx) * scalex + botx;
  y = (y - oboty) * scaley + boty;
  hix = (x >> 5) & 037;
  hiy = (y >> 5) & 037;
  lox = x & 037;
  loy = y & 037;
  n = (abs(hix - ohix) + abs(hiy - ohiy) + 6) / 12;
  if (hiy != ohiy) {
    putch(hiy | 040);
    ohiy = hiy;
  }
  if (hix != ohix) {
    putch(loy | 0140);
    putch(hix | 040);
    ohix = hix;
    oloy = loy;
  } else if (loy != oloy) {
    putch(loy | 0140);
    oloy = loy;
  }
  putch(lox | 0100);
  while (n--)
    putch(0);
}
