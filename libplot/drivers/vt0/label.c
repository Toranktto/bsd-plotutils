#include "vt0.h"

void pl_label(char *s) {
  int i, o;

  o = 01401;
  write(vti, &o, 2);
  for (i = 0; s[i++];)
    ;
  write(vti, s, i);
}
