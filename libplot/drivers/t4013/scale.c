#include "t4013.h"

void scale(int i, double x, double y) {
  switch (i) {
  default:
    return;
  case 'c':
    x *= 2.54;
    y *= 2.54;
  case 'i':
    x /= 200;
    y /= 200;
  case 'u':
    scalex = 1 / x;
    scaley = 1 / y;
  }
  scaleflag = 1;
}
