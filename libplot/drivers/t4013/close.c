#include <stdio.h>
pl_closevt() {
  putch(037);
  fflush(stdout);
}
pl_close() {
  putch(037);
  fflush(stdout);
}
