#include "vt0.h"

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
