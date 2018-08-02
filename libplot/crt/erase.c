#ifndef lint
static char sccsid[] = "@(#)crtplot.c	4.1 (Berkeley) 11/11/83";
#endif /* not lint */

#include "crt.h"
#include <plot.h>

void
pl_erase(void)
{
	clear();
	move(LINES-1, 0);
	lastX = 0;
	lastY = LINES-1;
}
