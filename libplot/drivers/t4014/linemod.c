#include "t4014.h"

void pl_linemod(char *s) {
  char c;
  putch(033);
  switch (s[0]) {
  case 'l':
    c = 'd';
    break;
  case 'd':
    if (s[3] != 'd')
      c = 'a';
    else
      c = 'b';
    break;
  case 's':
    if (s[5] != '\0')
      c = 'c';
    else
      c = '`';
  }
  putch(c);
}
