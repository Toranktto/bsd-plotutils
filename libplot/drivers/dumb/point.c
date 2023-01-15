#include "dumb.h"

void pl_point(int x, int y) {
  scale(x, y);
  currentx = x;
  currenty = y;
  screenmat[currentx][currenty] = '*';
}
