#include "con.h"
pl_label(s) char *s;
{
  int i, c;
  while ((c = *s++) != '\0') {
    xnow += HORZRES;
    spew(c);
  }
  return;
}
