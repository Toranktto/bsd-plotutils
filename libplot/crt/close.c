/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "@(#)close.c	5.1 (Berkeley) 5/7/85";
#endif /* not lint */

#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "crt.h"
#include <plot.h>

void
pl_closepl(void)
{
	FILE *ctty;
	char ctty_path[L_ctermid];
	register char c;

	signal(SIGINT, SIG_IGN);
	/* Leave cursor at top of screen. */
	move(0, 0);
	refresh();

	/* wait for 'q' from controlling terminal, because stdin or stdscr can be redirected */
	if (ctermid(ctty_path) != NULL && (ctty = fopen(ctty_path, "rb")) != NULL) {
		while((c = fgetc(ctty)) != EOF)
			if (c == 'q') break;

		fclose(ctty);
	}

	endwin();
	exit(0);
}
