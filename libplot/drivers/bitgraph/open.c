/*
 * Displays plot files on a BBN bitgraph terminal.
 */

#include "bg.h"
#include <signal.h>

int currentx = 0;
int currenty = 0;
double lowx = 0.0;
double lowy = 0.0;
double scale = 1.0;

void pl_open(void) {
  void pl_close();

  /* catch interupts */
  signal(SIGINT, (void (*)(int))pl_close);
  currentx = 0;
  currenty = 0;

  pl_space(0, 0, XMAX, YMAX);
}
