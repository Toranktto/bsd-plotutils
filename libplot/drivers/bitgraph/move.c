#include "bg.h"

pl_move(xi, yi) int xi, yi;
{
  currentx = scaleX(xi);
  currenty = scaleY(yi);
  putchar(ESC);
  printf(":%d;%dm", currentx, currenty);
}
