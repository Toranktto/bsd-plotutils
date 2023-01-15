#include "gigi.h"

void pl_move(int xi, int yi) {
  currentx = xsc(xi);
  currenty = ysc(yi);
  printf("P[%d,%d]", currentx, currenty);
}
