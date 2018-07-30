#ifndef lint
static char sccsid[] = "@(#)crtplot.c	4.1 (Berkeley) 11/11/83";
#endif /* not lint */

#include "crt.h"
#include <plot.h>

extern void screen_move(int y, int x);

void
pl_move(int x, int y)
{
	screen_move(scaleY(y), scaleX(x));
}
