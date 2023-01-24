#include "bg.h"

void pl_circle(int xc, int yc, int r) {
  pl_arc(xc, yc, xc + r, yc, xc - r, yc);
  pl_arc(xc, yc, xc - r, yc, xc + r, yc);
}
