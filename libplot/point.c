#include "plotinternal.h"

void pl_point(int xi, int yi) {
  putc('p', stdout);
  putsi(xi);
  putsi(yi);
}
