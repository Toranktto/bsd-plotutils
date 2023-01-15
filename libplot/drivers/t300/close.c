#include <stdio.h>
pl_closevt() { pl_close(); }
pl_close() {
  fflush(stdout);
  reset();
}
