#include "aed.h"

/*---------------------------------------------------------
 *	pl_close does whatever is necessary to reset the characteristics
 *	of the AED512 after the program is finished.
 *
 *	Results:	None.
 *
 *	Side Effects:
 *	The graphics display modes are reset.
 *---------------------------------------------------------
 */
void pl_close(void) {
  fputs("Q00204\6", stdout);
  fflush(stdout);
  stty(fileno(stdout), &sgttyb);
}
