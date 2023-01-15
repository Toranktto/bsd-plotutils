#include "hp7221.h"

pl_point(xi, yi) int xi, yi;
{
  if (scaleX(xi) != currentx || scaleY(yi) != currenty)
    pl_move(xi, yi);
  pl_cont(xi, yi);
}
