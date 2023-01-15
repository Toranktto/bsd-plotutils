#include "aed.h"

/*---------------------------------------------------------
 *	Circle draws a circle.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A circle of radius r is drawn at (x,y).
 *---------------------------------------------------------
 */
void pl_circle(int x, int y, int r) {
  char buf[3];
  setcolor("01");
  putc('Q', stdout);
  outxy20(x, y);
  putc('O', stdout);
  chex((r * scale) >> 12, buf, 2);
  fputs(buf, stdout);
  (void)fflush(stdout);
}
