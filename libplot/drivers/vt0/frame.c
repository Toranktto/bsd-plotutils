#include "vt0.h"

void pl_frame(int n) {
  n = (n & 0377) | 02000;
  write(vti, &n, 2);
}
