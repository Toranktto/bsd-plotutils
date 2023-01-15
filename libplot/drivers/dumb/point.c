#include "dumb.h"

pl_point(x, y) int x, y;
{
  scale(x, y);
  currentx = x;
  currenty = y;
  screenmat[currentx][currenty] = '*';
}
