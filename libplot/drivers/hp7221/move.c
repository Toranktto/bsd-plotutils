#include "hp7221.h"

pl_move(xi, yi) int xi, yi;
{
  currentx = scaleX(xi);
  currenty = scaleY(yi);
  putchar('p');
  putMBP(currentx, currenty);
}
