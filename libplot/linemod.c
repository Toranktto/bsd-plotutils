#include <stdio.h>
pl_linemod(s) char *s;
{
  int i;
  putc('f', stdout);
  for (i = 0; s[i];)
    putc(s[i++], stdout);
  putc('\n', stdout);
}
