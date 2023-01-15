#include "bg.h"

pl_cont(xi, yi) int xi, yi;
{
  currentx = scaleX(xi);
  currenty = scaleY(yi);
  putchar(ESC);
  printf(":%d;%dd", currentx, currenty);
}
