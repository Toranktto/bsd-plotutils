#include "dumb.h"

void pl_cont(int x, int y) {
  int x1, y1;
  x1 = x;
  y1 = y;
  scale(x1, y1);
  dda_line('*', currentx, currenty, x, y);
}
