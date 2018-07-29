/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)close.c	5.1 (Berkeley) 6/7/85";
#endif /* not lint */

#include <plot.h>
#include <stdio.h>

extern void putch(int c);

void
closevt(void)
{
	putch(037);
	fflush(stdout);
}

void
closepl(void)
{
	putch(037);
	fflush(stdout);
}
