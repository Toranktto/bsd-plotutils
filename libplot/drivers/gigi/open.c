/*
 * Displays plot files on a gigi "graphics" terminal.
 */

#include "gigi.h"
#include <signal.h>

int currentx = 0;
int currenty = 0;
double lowx = 0.0;
double lowy = 0.0;
double scalex = 1.0;
double scaley = 1.0;

void pl_open(void) {
  /* catch interrupts */
  signal(SIGINT, (void (*)(int))pl_close);
  currentx = 0;
  currenty = 0;
  /* enter graphics mode */
  putchar(ESC);
  putchar('P');
  putchar('p');
  /* set some parameters */
  printf("S(I0 T0 [0,0])");
  pl_space(0, 0, XMAX, YMAX);
}
