/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)line.c	5.1 (Berkeley) 5/7/85";
#endif /* not lint */

#include "gigi.h"
#include <plot.h>

void
pl_line(int x0, int y0, int x1, int y1)
{
	if (xsc(x0) == currentx && ysc(y0) == currenty)
		pl_cont(x1, y1);
	else if (xsc(x1) == currentx && ysc(y1) == currenty)
		pl_cont(x0, y0);
	else{
		pl_move(x0, y0);
		pl_cont(x1, y1);
	}
}
