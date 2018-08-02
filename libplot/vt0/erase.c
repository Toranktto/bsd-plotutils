#ifndef lint
static char sccsid[] = "@(#)erase.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>
#include <unistd.h>

extern int vti;

void
pl_erase(void)
{
	int i;
	i = 0401;
	write(vti, &i, 2);
}
