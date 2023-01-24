#include "plotinternal.h"

void pl_linemod(char *s) {
  int i;
  putc('f', stdout);
  for (i = 0; s[i];)
    putc(s[i++], stdout);
  putc('\n', stdout);
}
