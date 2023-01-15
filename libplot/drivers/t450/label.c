#include "con.h"
void pl_label(char *s) {
  int c;
  while ((c = *s++) != '\0') {
    xnow += 6;
    spew(c);
  }
  return;
}
