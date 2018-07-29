#ifndef lint
static char sccsid[] = "@(#)dot.c	4.1 (Berkeley) 6/27/83";
#endif

extern int vti;

void
dot(int xi, int yi, int dx, int n, pat[])
{
	struct {char pad,c; int xi,yi,dx;} p;
	p.c = 7;
	p.xi = xsc(xi);
	p.yi = ysc(yi);
	p.dx = xsc(dx);
	write(vti,&p.c,7);
	write(vti,pat,n?n&0377:256);
}
