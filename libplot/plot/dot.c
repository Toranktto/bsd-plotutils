#ifndef lint
static char sccsid[] = "@(#)dot.c	4.1 (Berkeley) 6/27/83";
#endif

#include <stdio.h>
#include <plot.h>

extern void putsi(int a);

void
pl_dot(int xi, int yi, int dx, int n, int pat[])
{
	int i;
	putc('d', stdout);
	putsi(xi);
	putsi(yi);
	putsi(dx);
	putsi(n);
	for (i = 0; i < n; i++) putsi(pat[i]);
}
