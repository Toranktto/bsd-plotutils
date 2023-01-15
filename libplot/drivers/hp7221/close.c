#include "hp7221.h"
#include <signal.h>

pl_close() {
  /* receive interupts */
  signal(SIGINT, SIG_IGN);
  printf("v@}"); /* Put pen away. */
  fflush(stdout);
}
