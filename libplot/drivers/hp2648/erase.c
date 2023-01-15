#include "hp2648.h"

void pl_erase(void) {
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
