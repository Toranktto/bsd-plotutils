#include "hp7221.h"

void pl_label(char *s) {
  printf("~'%s", s);
  putchar(ENDOFSTRING);
}
