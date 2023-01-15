#include "aed.h"

/*---------------------------------------------------------
 *	This routine erases the screen.
 *
 *	Results:	None.
 *	Side Effects:	The screen is cleared.
 *---------------------------------------------------------
 */
pl_erase() {
  setcolor("FF");
  putc('\14', stdout);
  putc('\33', stdout);
  putc('Q', stdout);
  outxy20(curx, cury);
  (void)fflush(stdout);
}
