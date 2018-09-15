/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)linemd.c	5.1 (Berkeley) 6/7/85";
#endif				/* not lint */

#include <plot.h>

void
pl_linemod_(register char *s, long len)
{
	char		buf[256];
	register char  *cp, *cend;

	cp = buf;
	cend = cp + (len < 255 ? len : 255);
	while (cp < cend && *s != ' ')
		*cp++ = *s++;
	*cp = 0;
	pl_linemod(buf);
}
