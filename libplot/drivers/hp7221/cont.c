#include "hp7221.h"

pl_cont(xi, yi) int xi, yi;
{
  currentx = scaleX(xi);
  currenty = scaleY(yi);
  putchar('q');
  putMBP(currentx, currenty);
}
