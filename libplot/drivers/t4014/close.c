#include <stdio.h>
void pl_close(void) {
  putch(037);
  fflush(stdout);
}