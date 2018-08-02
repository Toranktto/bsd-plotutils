/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)point.c	5.1 (Berkeley) 5/7/85";
#endif /* not lint */

#include "hp7221.h"
#include <plot.h>

void
pl_point(int xi, int yi)
{
	if (scaleX(xi) != currentx || scaleY(yi) != currenty)
		pl_move(xi, yi);
	pl_cont(xi, yi);
}
