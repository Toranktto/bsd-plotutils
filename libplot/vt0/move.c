#ifndef lint
static char sccsid[] = "@(#)move.c	4.1 (Berkeley) 6/27/83";
#endif

extern int vti;
extern int xnow,ynow;

void
move(int xi, int yi)
{
	struct {char pad,c; int x,y;} p;
	p.c = 9;
	p.x = xnow = xsc(xi);
	p.y = ynow = ysc(yi);
	write(vti,&p.c,5);
}
