#include "hp7221.h"

void pl_move(int xi, int yi) {
  currentx = scaleX(xi);
  currenty = scaleY(yi);
  putchar('p');
  putMBP(currentx, currenty);
}
