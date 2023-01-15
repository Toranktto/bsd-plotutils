#include "hp7221.h"

void pl_cont(int xi, int yi) {
  currentx = scaleX(xi);
  currenty = scaleY(yi);
  putchar('q');
  putMBP(currentx, currenty);
}
