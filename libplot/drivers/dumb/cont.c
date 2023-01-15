#include "dumb.h"

pl_cont(x, y) int x, y;
{
  int x1, y1;
  x1 = x;
  y1 = y;
  scale(x1, y1);
  dda_pl_line('*', currentx, currenty, x, y);
}
