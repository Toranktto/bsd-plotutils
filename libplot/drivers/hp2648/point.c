#include "hp2648.h"

pl_point(xi, yi) int xi, yi;
{
  if (xsc(xi) != currentx || ysc(yi) != currenty)
    pl_move(xi, yi);
  buffready(1);
  putchar('d');
}
