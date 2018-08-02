/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)line.c	5.2 (Berkeley) 4/30/85";
#endif /* not lint */

#include "bg.h"
#include <plot.h>

void
pl_line(int x0, int y0, int x1, int y1)
{
	if (scaleX(x0) == currentx && scaleY(y0) == currenty)
		pl_cont(x1, y1);
	else if (scaleX(x1) == currentx && scaleY(y1) == currenty)
		pl_cont(x0, y0);
	else{
		pl_move(x0, y0);
		pl_cont(x1, y1);
	}
}
