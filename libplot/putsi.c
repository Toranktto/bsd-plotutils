#include <stdio.h>
void putsi(int a) {
  putc((char)a, stdout);
  putc((char)(a >> 8), stdout);
}
