#include "hp2648.h"

void pl_label(char *s) {
  handshake();
  putchar(ESC);
  putchar(GRAPHIC);
  putchar('l');
  for (; *s != '\0'; s++)
    putchar(*s);
  putchar(ESC);
  putchar(GRAPHIC);
  putchar('d');
  putchar('T');
  handshake();
  putchar(ESC);
  putchar(GRAPHIC);
  putchar(PLOT);
  putchar(BINARY);
  buffcount = 4;
}
