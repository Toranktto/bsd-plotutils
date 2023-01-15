#include "hp2648.h"

void pl_close(void) {
  putchar('Z');
  fflush(stdout);
  if (shakehands == TRUE) {
    stty(fildes, &sarg);
    close(fildes);
  }
}
