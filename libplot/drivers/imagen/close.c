#include "imPcodes.h"
#include "imp.h"

pl_close() {
  putch(imP_ENDPAGE);
  fflush(stdout);
}
