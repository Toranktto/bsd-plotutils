#include "con.h"
pl_erase() {
  int i;
  for (i = 0; i < 11 * (VERTRESP / VERTRES); i++)
    spew(DOWN);
  return;
}
