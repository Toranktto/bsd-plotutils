#include "t4013.h"

void pl_label(char *s) {
  register int i, c;
  putch(037); /* alpha mode */
  for (i = 0; (c = s[i]); i++)
    putch(c);
}
