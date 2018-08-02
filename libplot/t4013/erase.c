/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)erase.c	5.1 (Berkeley) 6/7/85";
#endif /* not lint */

#include <plot.h>

extern int ohiy;
extern int ohix;
extern int oloy;

extern void putch(int c);

void
pl_erase(void)
{
	int i;
	putch(033);
	putch(014);
	ohiy = -1;
	ohix = -1;
	oloy = -1;
}
