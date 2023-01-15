#include "gigi.h"

void pl_label(char *s) {
  printf("T(S0 H2 D0 I0) \"");
  for (; *s != '\0'; s++) {
    putchar(*s);
    if (*s == '"')
      putchar('"');
  }
  putchar('"');
}
