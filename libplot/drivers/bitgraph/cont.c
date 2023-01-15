#include "bg.h"

void pl_cont(int xi, int yi) {
  currentx = scaleX(xi);
  currenty = scaleY(yi);
  putchar(ESC);
  printf(":%d;%dd", currentx, currenty);
}
