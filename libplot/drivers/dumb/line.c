#include "dumb.h"

pl_line(x0, y0, x1, y1) int x0, y0, x1, y1;
{
  int x, y;

  scale(x0, y0);
  x = x1;
  y = y1;
  scale(x, y);
  currentx = x0;
  currenty = y0;
  screenmat[currentx][currenty] = '*';
  dda_pl_line('*', x0, y0, x1, y1);
}
