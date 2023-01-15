#include "hp7221.h"

pl_label(s) char *s;
{
  printf("~'%s", s);
  putchar(ENDOFSTRING);
}
