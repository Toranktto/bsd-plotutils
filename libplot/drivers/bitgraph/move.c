#include "bg.h"

void pl_move(int xi, int yi) {
  currentx = scaleX(xi);
  currenty = scaleY(yi);
  putchar(ESC);
  printf(":%d;%dm", currentx, currenty);
}
