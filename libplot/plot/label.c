#ifndef lint
static char sccsid[] = "@(#)label.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

void
label(char *s)
{
	int i;
	putc('t',stdout);
	for(i=0;s[i];)putc(s[i++],stdout);
	putc('\n',stdout);
}
