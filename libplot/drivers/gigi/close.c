#include "gigi.h"
#include <signal.h>

void pl_close(void) {
  /* recieve interupts */
  signal(SIGINT, SIG_IGN);

  /* exit graphics mode */
  putchar(ESC);
  putchar('\\');

  exit(0);
}
