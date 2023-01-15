#include "hp2648.h"

void pl_cont(int xi, int yi) {
  char xb1, xb2, yb1, yb2;
  itoa(xsc(xi), &xb1, &xb2);
  itoa(ysc(yi), &yb1, &yb2);
  buffready(4);
  putchar(xb2);
  putchar(xb1);
  putchar(yb2);
  putchar(yb1);
  currentx = xsc(xi);
  currenty = ysc(yi);
}
