#include "dumb.h"

void pl_label(char *string) {
  while (*string != '\0' && currentx < COLS) {
    screenmat[currentx][currenty] = *string++;
    currentx++;
  }
  if (currentx == COLS)
    currentx = currentx - 1;
}
