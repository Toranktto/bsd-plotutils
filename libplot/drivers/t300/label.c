#include "con.h"
pl_label(s) char *s;
{
  int i, c;
  while ((c = *s++) != '\0') {
    xnow += 6;
    spew(c);
  }
  return;
}
