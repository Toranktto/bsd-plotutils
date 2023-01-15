#include "gigi.h"
#include <signal.h>

pl_close() {
  /* recieve interupts */
  signal(SIGINT, SIG_IGN);

  /* exit graphics mode */
  putchar(ESC);
  putchar('\\');

  exit(0);
}
