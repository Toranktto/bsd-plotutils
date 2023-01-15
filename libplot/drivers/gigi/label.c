#include "gigi.h"

pl_label(s) char *s;
{
  printf("T(S0 H2 D0 I0) \"");
  for (; *s != '\0'; s++) {
    putchar(*s);
    if (*s == '"')
      putchar('"');
  }
  putchar('"');
}
