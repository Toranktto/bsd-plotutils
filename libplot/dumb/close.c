/*
 * Copyright (c) 1980 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)close.c	5.1 (Berkeley) 5/7/85";
#endif				/* not lint */

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "dumb.h"
#include <plot.h>

void
pl_closepl(void)
{
	int		i, j;

	signal(SIGINT, SIG_IGN);

	for (j = 0; j < LINES; j++) {
		for (i = 0; i < COLS; i++) {
			printf("%c", screenmat[i][j]);
		}
		printf("\n");
	}
}

void
pl_closevt(void)
{
	signal(SIGINT, SIG_IGN);
}
