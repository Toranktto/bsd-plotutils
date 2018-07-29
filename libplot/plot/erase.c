#ifndef lint
static char sccsid[] = "@(#)erase.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>

void
erase(void)
{
	putc('e',stdout);
}
