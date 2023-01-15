#include "hp7221.h"
#include <signal.h>

void pl_close(void) {
  /* receive interupts */
  signal(SIGINT, SIG_IGN);
  printf("v@}"); /* Put pen away. */
  fflush(stdout);
}
