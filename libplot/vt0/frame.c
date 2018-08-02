#ifndef lint
static char sccsid[] = "@(#)frame.c	4.1 (Berkeley) 6/27/83";
#endif

#include <unistd.h>

extern int vti;

void
frame(int n)
{
	n = n & 0377 | 02000;
	write(vti, &n, 2);
}
