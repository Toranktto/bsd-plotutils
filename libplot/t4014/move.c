#ifndef lint
static char sccsid[] = "@(#)move.c	4.1 (Berkeley) 6/27/83";
#endif

void
move(int xi, int yi)
{
	putch(035);
	cont(xi,yi);
}
