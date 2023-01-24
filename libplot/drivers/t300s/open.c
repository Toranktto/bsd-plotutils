#include "con.h"

int xnow, ynow;
int OUTF;
struct sgttyb ITTY, PTTY;
float HEIGHT = 6.0, WIDTH = 6.0, OFFSET = 0.0;
int xscale, xoffset, yscale;
float botx = 0., boty = 0., obotx = 0., oboty = 0.;
float scalex = 1., scaley = 1.;

void pl_open(void) {
  xnow = ynow = 0;
  OUTF = 1;
  printf("\r");
  gtty(OUTF, &ITTY);
  signal(2, (void (*)(int))reset);
  PTTY = ITTY;
  PTTY.sg_flags &= ~CRMOD; /* don't map lf */
  /* initialize constants */
  xscale = 4096. / (HORZRESP * WIDTH);
  yscale = 4096 / (VERTRESP * HEIGHT);
  xoffset = OFFSET * HORZRESP;
  return;
}
