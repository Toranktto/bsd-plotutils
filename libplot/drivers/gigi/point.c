#include "gigi.h"

pl_point(xi, yi) int xi, yi;
{
  if (xsc(xi) != currentx || ysc(yi) != currenty)
    pl_move(xi, yi);
  printf("V[]");
}
