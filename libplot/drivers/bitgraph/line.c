#include "bg.h"

pl_line(x0, y0, x1, y1) int x0, y0, x1, y1;
{
  if (scaleX(x0) == currentx && scaleY(y0) == currenty)
    pl_cont(x1, y1);
  else if (scaleX(x1) == currentx && scaleY(y1) == currenty)
    pl_cont(x0, y0);
  else {
    pl_move(x0, y0);
    pl_cont(x1, y1);
  }
}
