#include <stdio.h>
void pl_space(int x0, int y0, int x1, int y1) {
  putc('s', stdout);
  putsi(x0);
  putsi(y0);
  putsi(x1);
  putsi(y1);
}
