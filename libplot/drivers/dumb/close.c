#include "dumb.h"
#include <signal.h>

pl_close() {
  int i, j;

  for (j = 0; j < LINES; j++) {
    for (i = 0; i < COLS; i++) {
      printf("%c", screenmat[i][j]);
    }
    printf("\n");
  }
  signal(SIGINT, SIG_IGN);
  exit(0);
}
