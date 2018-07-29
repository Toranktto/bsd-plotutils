/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)move.c	5.1 (Berkeley) 6/7/85";
#endif /* not lint */

#include <plot.h>

extern void putch(int c);

void
move(int xi, int yi)
{
	putch(035);
	cont(xi,yi);
}
