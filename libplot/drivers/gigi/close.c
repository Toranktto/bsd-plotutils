#include "gigi.h"
#include <signal.h>

void pl_close(void) {
  /* receive interrupts */
  signal(SIGINT, SIG_IGN);

  /* exit graphics mode */
  putchar(ESC);
  putchar('\\');

  exit(0);
}
