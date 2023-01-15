#include <stdio.h>
pl_dot(xi, yi, dx, n, pat) int pat[];
{
  int i;
  putc('d', stdout);
  putsi(xi);
  putsi(yi);
  putsi(dx);
  putsi(n);
  for (i = 0; i < n; i++)
    putsi(pat[i]);
}
