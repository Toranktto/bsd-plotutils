#include "hp2648.h"

void handshake(void) {
  int i;
  char ch;

  if (shakehands != TRUE)
    return;
  ch = ' ';
  putchar(ENQ);
  fflush(stdout);
  while (1) {
    i = read(fildes, &ch, 1);
    if (i < 0)
      continue;
    if (ch == ACK)
      break;
    putchar('Z');
    fflush(stdout);
    stty(fildes, &sarg);
    exit(0);
  }
}

void buffready(int n) {
  buffcount = buffcount + n;
  if (buffcount >= 80) {
    handshake();
    putchar(ESC);
    putchar(GRAPHIC);
    putchar(PLOT);
    putchar(BINARY);
    buffcount = n + 4;
  }
}

void itoa(int num, char *byte1, char *byte2) {
  *byte1 = (num & 037) | 040;
  *byte2 = ((num >> 5) & 037) | 040;
}
