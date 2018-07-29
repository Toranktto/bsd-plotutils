#ifndef lint
static char sccsid[] = "@(#)subr.c	4.1 (Berkeley) 6/27/83";
#endif

extern float obotx;
extern float oboty;
extern float boty;
extern float botx;
extern float scalex;
extern float scaley;

int
xsc(int xi)
{
	int xa;
	xa = (xi-obotx)*scalex+botx;
	return(xa);
}

int
ysc(int yi)
{
	int ya;
	ya = (yi-oboty)*scaley+boty;
	return(ya);
}
