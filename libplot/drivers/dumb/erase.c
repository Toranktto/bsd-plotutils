#include "dumb.h"

pl_erase() {
  register int i, j;

  for (i = 0; i < COLS; i++)
    for (j = 0; j < LINES; j++)
      screenmat[i][j] = ' ';
}
