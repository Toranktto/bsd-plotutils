/*
 * Copyright (c) 1985 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)linemod.c	5.3 (Berkeley) 9/21/85";
#endif				/* not lint */

#include "imp.h"
#include <stdlib.h>
#include <plot.h>

extern void	setfont(char *c, int sz);

/*
 * Hack to set font.
 */
void
pl_linemod(char *s)
{
	register char  *tit;
	register char  *nam;
	int		siz = 0;
	nam = s;
	for (tit = "charset="; *tit;)
		if (*tit++ != *nam++)
			return;
	s = nam;
	while (*nam)
		switch (*nam++) {
		case ',':
		case '\n':
			*--nam = 0;
		}
	siz = atoi(++nam);
	if (siz == 0) {
		while (*--nam >= '0' && *nam <= '9');
		siz = (atoi(++nam) * 4) / 3;
	}
	if (siz == 0)
		siz = imPcsize;
	setfont(s, siz);
}
