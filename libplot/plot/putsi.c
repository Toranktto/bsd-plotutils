#ifndef lint
static char	sccsid[] = "@(#)putsi.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>
#include <netinet/in.h>

void
putsi(int a)
{
	short		b;

	b = htons(a);
	fwrite(&b, sizeof(b), 1, stdout);
}
