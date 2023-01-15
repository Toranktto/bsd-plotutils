#include "imp.h"

/*
 * Hack to set font.
 */
pl_linemod(s) char *s;
{
  register char *tit;
  register char *nam;
  int siz = 0;
  nam = s;
  for (tit = "charset="; *tit;)
    if (*tit++ != *nam++)
      return;
  s = nam;
  while (*nam)
    switch (*nam++) {
    case ',':
    case '\n':
      *--nam = 0;
    }
  siz = atoi(++nam);
  if (siz == 0) {
    while (*--nam >= '0' && *nam <= '9')
      ;
    siz = (atoi(++nam) * 4) / 3;
  }
  if (siz == 0)
    siz = imPcsize;
  setfont(s, siz);
}
