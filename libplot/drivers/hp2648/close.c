#include "hp2648.h"

pl_close() {
  putchar('Z');
  fflush(stdout);
  if (shakehands == TRUE) {
    stty(fildes, &sarg);
    close(fildes);
  }
}
