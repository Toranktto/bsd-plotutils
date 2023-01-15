#include "hp2648.h"

pl_erase() {
  buffready(8);
  putchar(ESC);
  putchar(GRAPHIC);
  putchar(DISPLAY);
  putchar('a');
  putchar(ESC);
  putchar(GRAPHIC);
  putchar(PLOT);
  putchar(BINARY);
}
