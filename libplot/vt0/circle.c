#ifndef lint
static char sccsid[] = "@(#)circle.c	4.1 (Berkeley) 6/27/83";
#endif

extern vti;

void
circle(int x, int y, int r)
{
	char c;

	c = 5;
	write(vti,&c,1);
	write(vti,&x,6);
}
