#include "hp2648.h"

void pl_move(int xi, int yi) {
  char xb1, xb2, yb1, yb2;
  itoa(xsc(xi), &xb1, &xb2);
  itoa(ysc(yi), &yb1, &yb2);
  buffready(5);
  putchar(PENUP);
  putchar(xb2);
  putchar(xb1);
  putchar(yb2);
  putchar(yb1);
  currentx = xsc(xi);
  currenty = ysc(yi);
}
