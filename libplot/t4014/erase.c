#ifndef lint
static char sccsid[] = "@(#)erase.c	4.2 (Berkeley) 1/2/85";
#endif

#include <plot.h>

extern int ohiy;
extern int ohix;
extern int oloy;
extern int oextra;

extern void putch(int c);

void
pl_erase(void)
{
	int i;
	putch(033);
	putch(014);
	ohiy= -1;
	ohix = -1;
	oextra = -1;
	oloy = -1;
}
