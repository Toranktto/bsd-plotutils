#ifndef lint
static char sccsid[] = "@(#)line.c	4.1 (Berkeley) 6/27/83";
#endif

void
line(int x0, int y0, int x1, int y1)
{
	move(x0,y0);
	cont(x1,y1);
}
