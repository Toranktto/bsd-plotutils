/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)label.c	5.1 (Berkeley) 6/7/85";
#endif /* not lint */

#include <plot.h>

extern void putch(int c);

void
label(char *s)
{
	register int i,c;

	putch(037);	/* alpha mode */
	for(i=0; (c=s[i]); i++)
		putch(c);
}
