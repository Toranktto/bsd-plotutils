#include "aed.h"

/*---------------------------------------------------------
 *	Cont plots a line between (curx, cury) and (x, y).
 *
 *	Results:	None.
 *	Side Effects:	As above.
 *---------------------------------------------------------
 */
pl_cont(x, y) int x, y;
{ pl_line(curx, cury, x, y); }
