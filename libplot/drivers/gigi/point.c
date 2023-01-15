#include "gigi.h"

void pl_point(int xi, int yi) {
  if (xsc(xi) != currentx || ysc(yi) != currenty)
    pl_move(xi, yi);
  printf("V[]");
}
