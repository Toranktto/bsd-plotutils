#include "hp2648.h"
#include <sgtty.h>

int shakehands;
int currentx;
int currenty;
int buffcount;
int fildes;
float lowx;
float lowy;
float scalex;
float scaley;
struct sgttyb sarg;

void pl_open(void) {
  if (isatty(fileno(stdout))) {
    shakehands = TRUE;
    fildes = open(TERMINAL, 0);
    gtty(fildes, &sarg);
    sarg.sg_flags = sarg.sg_flags | RAW;
    stty(fildes, &sarg);
    sarg.sg_flags = sarg.sg_flags & ~RAW;
  } else {
    shakehands = FALSE;
  }
  buffcount = 0;
  currentx = 0;
  currenty = 0;
  buffready(8);
  putchar(ESC);
  putchar(GRAPHIC);
  putchar(DISPLAY);
  putchar('c');
  putchar(ESC);
  putchar(GRAPHIC);
  putchar(PLOT);
  putchar(BINARY);
  pl_space(0, 0, 720, 360);
}
