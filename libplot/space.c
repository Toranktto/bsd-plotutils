#include <stdio.h>
pl_space(x0, y0, x1, y1) {
  putc('s', stdout);
  putsi(x0);
  putsi(y0);
  putsi(x1);
  putsi(y1);
}
