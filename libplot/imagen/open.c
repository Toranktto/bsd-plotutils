/*
 * Copyright (c) 1985 Regents of the University of California. All rights
 * reserved.  The Berkeley software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef lint
static char	sccsid[] = "@(#)open.c	5.2 (Berkeley) 9/21/85";
#endif				/* not lint */

#include "imPcodes.h"
#include "imp.h"
#include <plot.h>

extern void	putwd(int w);
extern void	putch(int c);

void
setfont(char *c, int sz)
{
	imPcsize = sz;
	putch(imP_CREATE_FAMILY_TABLE);
	putch(2);
	putch(1);
	putch(0);
	fprintf(stdout, "%s", c);
	putch(0);
}

void
pl_openpl(void)
{
	pl_openvt();
}

void
pl_openvt(void)
{
	putch(imP_SET_HV_SYSTEM);
	putch((3 << 3) | 5);
	putch(imP_SET_FAMILY);
	putch(2);
	setfont(imP_charset, imPcsize);
	putch(imP_SET_IL);
	putwd(imPcsize + 3);
	putch(imP_SET_SP);
	putwd(imPcsize);
	putch(imP_SET_PEN);
	putch(2);
	putch(imP_SET_ABS_H);
	putwd(0);
	putch(imP_SET_ABS_V);
	putwd(0);
}
