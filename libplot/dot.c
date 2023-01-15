#include <stdio.h>
void pl_dot(int xi, int yi, int dx, int n, int pat[]) {
  int i;
  putc('d', stdout);
  putsi(xi);
  putsi(yi);
  putsi(dx);
  putsi(n);
  for (i = 0; i < n; i++)
    putsi(pat[i]);
}
