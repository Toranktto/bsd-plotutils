#include "imPcodes.h"
#include "imp.h"

void pl_close(void) {
  putch(imP_ENDPAGE);
  fflush(stdout);
}
