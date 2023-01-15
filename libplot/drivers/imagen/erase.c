#include "imPcodes.h"
#include "imp.h"
pl_erase() {
  int i;
  putch(imP_ENDPAGE);
  imPx = imPy = 0;
  return;
}
