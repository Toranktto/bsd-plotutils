#include "gigi.h"

pl_move(xi, yi) int xi, yi;
{
  currentx = xsc(xi);
  currenty = ysc(yi);
  printf("P[%d,%d]", currentx, currenty);
}
