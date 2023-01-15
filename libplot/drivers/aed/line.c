#include "aed.h"

/*---------------------------------------------------------
 *	Line draws a line between two points.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	A line is drawn on the screen between (x1, y1) and (x2, y2).
 *---------------------------------------------------------
 */
pl_line(x1, y1, x2, y2) int x1, y1, x2, y2;
{
  setcolor("01");
  putc('Q', stdout);
  outxy20(x1, y1);
  putc('A', stdout);
  outxy20(x2, y2);
  (void)fflush(stdout);
  curx = x2;
  cury = y2;
}
