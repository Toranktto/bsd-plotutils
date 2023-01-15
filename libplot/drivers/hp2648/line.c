#include "hp2648.h"

void pl_line(int x0, int y0, int x1, int y1) {
  if (xsc(x0) == currentx && ysc(y0) == currenty)
    pl_cont(x1, y1);
  else if (xsc(x1) == currentx && ysc(y1) == currenty)
    pl_cont(x0, y0);
  else {
    pl_move(x0, y0);
    pl_cont(x1, y1);
  }
}
