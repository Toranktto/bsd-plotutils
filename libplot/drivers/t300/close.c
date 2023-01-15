#include <stdio.h>
void pl_close(void) {
  fflush(stdout);
  reset();
}
