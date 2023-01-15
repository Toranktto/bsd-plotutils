#include "aed.h"

/*---------------------------------------------------------
 *	This routine plots a single point.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A single point is displayed on the screen.
 *	The point is made the current point.
 *---------------------------------------------------------
 */
void pl_point(int x, int y) {
  setcolor("01");
  putc('Q', stdout);
  outxy20(x, y);
  fputs("O01", stdout);
  (void)fflush(stdout);
  curx = x;
  cury = y;
}
