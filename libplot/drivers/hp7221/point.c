#include "hp7221.h"

void pl_point(int xi, int yi) {
  if (scaleX(xi) != currentx || scaleY(yi) != currenty)
    pl_move(xi, yi);
  pl_cont(xi, yi);
}
