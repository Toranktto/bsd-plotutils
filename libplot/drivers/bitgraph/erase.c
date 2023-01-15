#include "bg.h"

void pl_erase(void) {
  putchar(ESC);
  printf("[H");
  putchar(ESC);
  printf("[J");
}
