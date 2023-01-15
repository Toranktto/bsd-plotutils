#include "bg.h"

pl_erase() {
  putchar(ESC);
  printf("[H");
  putchar(ESC);
  printf("[J");
}
