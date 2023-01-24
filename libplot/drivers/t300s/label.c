#include "con.h"

void pl_label(char *s) {
  int c;
  while ((c = *s++) != '\0') {
    xnow += HORZRES;
    spew(c);
  }
  return;
}
