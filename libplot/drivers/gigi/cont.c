#include "gigi.h"

void pl_cont(int xi, int yi) {
  currentx = xsc(xi);
  currenty = ysc(yi);
  printf("V[%d,%d]", currentx, currenty);
}
