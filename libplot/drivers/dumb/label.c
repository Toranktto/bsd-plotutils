#include "dumb.h"

pl_label(string) char *string;
{
  while (*string != '\0' && currentx < COLS) {
    screenmat[currentx][currenty] = *string++;
    currentx++;
  }
  if (currentx == COLS)
    currentx = currentx - 1;
}
