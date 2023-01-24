#include "con.h"

void pl_erase(void) {
  int i;
  for (i = 0; i < 11 * (VERTRESP / VERTRES); i++)
    spew(DOWN);
  return;
}
