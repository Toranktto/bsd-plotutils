#ifndef lint
static char sccsid[] = "@(#)erase.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

void
pl_erase(void)
{
	putc('e',stdout);
}
