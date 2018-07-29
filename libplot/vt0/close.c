#ifndef lint
static char sccsid[] = "@(#)close.c	4.1 (Berkeley) 6/27/83";
#endif

#include <plot.h>
#include <unistd.h>

extern int vti;

void
closevt(void)
{
	close(vti);
}

void
closepl(void)
{
	close(vti);
}
