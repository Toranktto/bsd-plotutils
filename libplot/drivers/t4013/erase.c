#include "t4013.h"

void pl_erase(void) {
  putch(033);
  putch(014);
  ohiy = -1;
  ohix = -1;
  oloy = -1;
  return;
}
