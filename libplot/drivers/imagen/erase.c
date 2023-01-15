#include "imPcodes.h"
#include "imp.h"
void pl_erase(void) {
  putch(imP_ENDPAGE);
  imPx = imPy = 0;
  return;
}
