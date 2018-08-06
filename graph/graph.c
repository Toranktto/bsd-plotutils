#ifndef lint
static char sccsid[] = "@(#)graph.c	4.2 3/30/83";
#endif

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <plot.h>
#include <string.h>
#define INF     HUGE
#define F       .25

struct xy {
	int xlbf;       /*flag:explicit lower bound*/
	int xubf;       /*flag:explicit upper bound*/
	int xqf;        /*flag:explicit quantum*/
	double (*xf)(); /*transform function, e.g. log*/
	float xa, xb;   /*scaling coefficients*/
	float xlb, xub;         /*lower and upper bound*/
	float xquant;   /*quantum*/
	float xoff;             /*screen offset fraction*/
	float xsize;            /*screen fraction*/
	int xbot, xtop;         /*screen coords of border*/
	float xmult;    /*scaling constant*/
} xd, yd;

struct val {
	float xv;
	float yv;
	int lblptr;
} *xx;

int xx_len;

char *labs_;
int labsiz;
int tick = 50;
int top = 4000;
int bot = 200;
float absbot;
int n;
int erasf = 1;
int gridf = 2;
int symbf = 0;
int absf = 0;
int transf;
int brkf;
float dx;
char *plotsymb;

#define BSIZ 80
char labbuf[BSIZ];
char titlebuf[BSIZ];

char *modes[] = {
	"disconnected",
	"solid",
	"dotted",
	"dotdashed",
	"shortdashed",
	"longdashed"
};
int mode = 1;

double
ident(double x)
{
	return(x);
}

void axes(void);
void transpose(void);
void readin(void);
void plot(void);
void limread(register struct xy *p, int *argcp, char ***argvp);
void title(void);
void badarg(void);
void setopt(int argc, char *argv[]);
void axlab(char c, struct xy *p);
int conv(float xv, register struct xy *p, int *ip);
void scale(register struct xy *p, struct val *v);
int setmark(int *xmark, register struct xy *p);
void submark(int *xmark, int *pxn, float x, struct xy *p);
void init(struct xy *p);
int copystring(int k);
int symbol(int ix, int iy, int k);
int getfloat(float *p);
int getstring(void);
int numb(float *np, int *argcp, register char ***argvp);

int
main(int argc, char *argv[])
{
	init(&xd);
	init(&yd);
	xd.xsize = yd.xsize = 1.;
	xx_len = 250;
	xx = (struct val *)malloc(xx_len * sizeof(struct val));
	labs_ = malloc(1);
	labs_[labsiz++] = 0;
	setopt(argc, argv);
	readin();
	transpose();
	pl_space(0, 0, 4096, 4096);
	if (erasf)
		pl_erase();
	scale(&xd, (struct val *)&xx->xv);
	scale(&yd, (struct val *)&xx->yv);
	axes();
	title();
	plot();
	pl_move(1, 1);
	pl_closevt();
	free(xx);
	free(labs_);
	return(0);
}

void
init(struct xy *p)
{
	p->xf = ident;
	p->xmult = 1;
}

void
setopt(int argc, char *argv[])
{
	char *p1, *p2;
	float temp;

	xd.xlb = yd.xlb = INF;
	xd.xub = yd.xub = -INF;
	while (--argc > 0) {
		argv++;
 again:         switch (argv[0][0]) {
		case '-':
			argv[0]++;
			goto again;
		case 'l': /* label for plot */
			p1 = titlebuf;
			if (argc >= 2) {
				argv++;
				argc--;
				p2 = argv[0];
				while ((*p1++ = *p2++));
			}
			break;

		case 'd': /*disconnected,obsolete option*/
		case 'm': /*line mode*/
			mode = 0;
			if (!numb(&temp, &argc, &argv))
				break;
			if (temp >= sizeof(modes) / sizeof(*modes))
				mode = 1;
			else if (temp >= 0)
				mode = temp;
			break;

		case 'a': /*automatic abscissas*/
			absf = 1;
			dx = 1;
			if (!numb(&dx, &argc, &argv))
				break;
			if (numb(&absbot, &argc, &argv))
				absf = 2;
			break;

		case 's': /*save screen, overlay plot*/
			erasf = 0;
			break;

		case 'g': /*grid style 0 none, 1 ticks, 2 full*/
			gridf = 0;
			if (!numb(&temp, &argc, &argv))
				temp = argv[0][1] - '0'; /*for caompatibility*/
			if (temp >= 0 && temp <= 2)
				gridf = temp;
			break;

		case 'c': /*character(s) for plotting*/
			if (argc >= 2) {
				symbf = 1;
				plotsymb = argv[1];
				argv++;
				argc--;
			}
			break;

		case 't':       /*transpose*/
			transf = 1;
			break;
		case 'b':       /*breaks*/
			brkf = 1;
			break;
		case 'x':       /*x limits */
			limread(&xd, &argc, &argv);
			break;
		case 'y':
			limread(&yd, &argc, &argv);
			break;
		case 'h': /*set height of plot */
			if (!numb(&yd.xsize, &argc, &argv))
				badarg();
			break;
		case 'w': /*set width of plot */
			if (!numb(&xd.xsize, &argc, &argv))
				badarg();
			break;
		case 'r': /* set offset to right */
			if (!numb(&xd.xoff, &argc, &argv))
				badarg();
			break;
		case 'u': /*set offset up the screen*/
			if (!numb(&yd.xoff, &argc, &argv))
				badarg();
			break;
		default:
			badarg();
		}
	}
}

void
limread(register struct xy *p, int *argcp, char ***argvp)
{
	if (*argcp > 1 && (*argvp)[1][0] == 'l') {
		(*argcp)--;
		(*argvp)++;
		p->xf = log10;
	}
	if (!numb(&p->xlb, argcp, argvp))
		return;
	p->xlbf = 1;
	if (!numb(&p->xub, argcp, argvp))
		return;
	p->xubf = 1;
	if (!numb(&p->xquant, argcp, argvp))
		return;
	p->xqf = 1;
}

int
numb(float *np, int *argcp, register char ***argvp)
{
	register char c;

	if (*argcp <= 1)
		return(0);
	while ((c = (*argvp)[1][0]) == '+')
		(*argvp)[1]++;
	if (!(isdigit(c) || (c == '-' && (*argvp)[1][1] < 'A') || c == '.'))
		return(0);
	*np = atof((*argvp)[1]);
	(*argcp)--;
	(*argvp)++;
	return(1);
}

void
readin(void)
{
	register int t;
	struct val *temp;

	if (absf == 1) {
		if (xd.xlbf)
			absbot = xd.xlb;
		else if (xd.xf == log10)
			absbot = 1;
	}

	for (;;) {
		if (n > xx_len) {
			xx_len *= 2;
			temp = (struct val *)realloc((char*)xx, xx_len * sizeof(struct val));
			if (temp == 0)
				return;
			xx = temp;
		}

		if (absf)
			xx[n].xv = n * dx + absbot;
		else
			if (!getfloat(&xx[n].xv))
				return;

		if (!getfloat(&xx[n].yv))
			return;

		xx[n].lblptr = -1;
		t = getstring();

		if (t > 0)
			xx[n].lblptr = copystring(t);

		n++;
		if (t < 0)
			return;
	}
}

void
transpose(void)
{
	register int i;
	float f;
	struct xy t;
	if (!transf)
		return;
	t = xd; xd = yd; yd = t;
	for (i = 0; i < n; i++) {
		f = xx[i].xv; xx[i].xv = xx[i].yv; xx[i].yv = f;
	}
}

int
copystring(int k)
{
	register char *temp;
	register int i;
	int q;

	temp = realloc(labs_, (unsigned)(labsiz + 1 + k));
	if (temp == 0)
		return(0);
	labs_ = temp;
	q = labsiz;
	for (i = 0; i <= k; i++)
		labs_[labsiz++] = labbuf[i];
	return(q);
}

float
modceil(float f, float t)
{
	t = fabs(t);
	return(ceil(f / t) * t);
}

float
modfloor(float f, float t)
{
	t = fabs(t);
	return(floor(f / t) * t);
}

void
getlim(register struct xy *p, struct val *v)
{
	register int i;

	i = 0;
	do {
		if (!p->xlbf && p->xlb > v[i].xv)
			p->xlb = v[i].xv;
		if (!p->xubf && p->xub < v[i].xv)
			p->xub = v[i].xv;
		i++;
	} while (i < n);
}

struct z {
	float lb, ub, mult, quant;
} setloglim(int lbf, int ubf, float lb, float ub), setlinlim(int lbf, int ubf, float xlb, float xub);

void
setlim(register struct xy *p)
{
	float t, delta, sign;
	struct z z;
	int mark[50];
	float lb, ub;
	int lbf, ubf;

	lb = p->xlb;
	ub = p->xub;
	delta = ub - lb;
	if (p->xqf) {
		if (delta * p->xquant <= 0)
			badarg();
		return;
	}
	sign = 1;
	lbf = p->xlbf;
	ubf = p->xubf;
	if (delta < 0) {
		sign = -1;
		t = lb;
		lb = ub;
		ub = t;
		t = lbf;
		lbf = ubf;
		ubf = t;
	}else if (delta == 0) {
		if (ub > 0) {
			ub = 2 * ub;
			lb = 0;
		}else
		if (lb < 0) {
			lb = 2 * lb;
			ub = 0;
		}else {
			ub = 1;
			lb = -1;
		}
	}
	if (p->xf == log10 && lb > 0 && ub > lb) {
		z = setloglim(lbf, ubf, lb, ub);
		p->xlb = z.lb;
		p->xub = z.ub;
		p->xmult *= z.mult;
		p->xquant = z.quant;
		if (setmark(mark, p) < 2) {
			p->xqf = lbf = ubf = 1;
			lb = z.lb; ub = z.ub;
		} else
			return;
	}
	z = setlinlim(lbf, ubf, lb, ub);
	if (sign > 0) {
		p->xlb = z.lb;
		p->xub = z.ub;
	} else {
		p->xlb = z.ub;
		p->xub = z.lb;
	}
	p->xmult *= z.mult;
	p->xquant = sign * z.quant;
}

struct z
setloglim(int lbf, int ubf, float lb, float ub)
{
	float r, s, t;
	struct z z;

	for (s = 1; lb * s < 1; s *= 10);
	lb *= s;
	ub *= s;
	for (r = 1; 10 * r <= lb; r *= 10);
	for (t = 1; t < ub; t *= 10);
	z.lb = !lbf ? r : lb;
	z.ub = !ubf ? t : ub;
	if (ub / lb < 100) {
		if (!lbf) {
			if (lb >= 5 * z.lb)
				z.lb *= 5;
			else if (lb >= 2 * z.lb)
				z.lb *= 2;
		}
		if (!ubf) {
			if (ub * 5 <= z.ub)
				z.ub /= 5;
			else if (ub * 2 <= z.ub)
				z.ub /= 2;
		}
	}
	z.mult = s;
	z.quant = r;
	return(z);
}

struct z
setlinlim(int lbf, int ubf, float xlb, float xub)
{
	struct z z;
	float r, s, delta;
	float ub, lb;

 loop:
	ub = xub;
	lb = xlb;
	delta = ub - lb;
	/*scale up by s, a power of 10, so range (delta) exceeds 1*/
	/*find power of 10 quantum, r, such that delta/10<=r<delta*/
	r = s = 1;
	while (delta * s < 10)
		s *= 10;
	delta *= s;
	while (10 * r < delta)
		r *= 10;
	lb *= s;
	ub *= s;
	/*set r=(1,2,5)*10**n so that 3-5 quanta cover range*/
	if (r >= delta / 2)
		r /= 2;
	else if (r < delta / 5)
		r *= 2;
	z.ub = ubf ? ub : modceil(ub, r);
	z.lb = lbf ? lb : modfloor(lb, r);
	if (!lbf && z.lb <= r && z.lb > 0) {
		xlb = 0;
		goto loop;
	}else if (!ubf && z.ub >= -r && z.ub < 0) {
		xub = 0;
		goto loop;
	}
	z.quant = r;
	z.mult = s;
	return(z);
}

void
scale(register struct xy *p, struct val *v)
{
	float edge;

	getlim(p, v);
	setlim(p);
	edge = top - bot;
	p->xa = p->xsize * edge / ((*p->xf)(p->xub) - (*p->xf)(p->xlb));
	p->xbot = bot + edge * p->xoff;
	p->xtop = p->xbot + (top - bot) * p->xsize;
	p->xb = p->xbot - (*p->xf)(p->xlb) * p->xa + .5;
}

void
axes(void)
{
	register int i;
	int mark[50];
	int xn, yn;
	if (gridf == 0)
		return;

	pl_line(xd.xbot, yd.xbot, xd.xtop, yd.xbot);
	pl_cont(xd.xtop, yd.xtop);
	pl_cont(xd.xbot, yd.xtop);
	pl_cont(xd.xbot, yd.xbot);

	xn = setmark(mark, &xd);
	for (i = 0; i < xn; i++) {
		if (gridf == 2)
			pl_line(mark[i], yd.xbot, mark[i], yd.xtop);
		if (gridf == 1) {
			pl_line(mark[i], yd.xbot, mark[i], yd.xbot + tick);
			pl_line(mark[i], yd.xtop - tick, mark[i], yd.xtop);
		}
	}
	yn = setmark(mark, &yd);
	for (i = 0; i < yn; i++) {
		if (gridf == 2)
			pl_line(xd.xbot, mark[i], xd.xtop, mark[i]);
		if (gridf == 1) {
			pl_line(xd.xbot, mark[i], xd.xbot + tick, mark[i]);
			pl_line(xd.xtop - tick, mark[i], xd.xtop, mark[i]);
		}
	}
}

int
setmark(int *xmark, register struct xy *p)
{
	int xn = 0;
	float x, xl, xu;
	float q;
	if (p->xf == log10 && !p->xqf) {
		for (x = p->xquant; x < p->xub; x *= 10) {
			submark(xmark, &xn, x, p);
			if (p->xub / p->xlb <= 100) {
				submark(xmark, &xn, 2 * x, p);
				submark(xmark, &xn, 5 * x, p);
			}
		}
	} else {
		xn = 0;
		q = p->xquant;
		if (q > 0) {
			xl = modceil(p->xlb + q / 6, q);
			xu = modfloor(p->xub - q / 6, q) + q / 2;
		} else {
			xl = modceil(p->xub - q / 6, q);
			xu = modfloor(p->xlb + q / 6, q) - q / 2;
		}
		for (x = xl; x <= xu; x += fabs(p->xquant))
			xmark[xn++] = (*p->xf)(x) * p->xa + p->xb;
	}
	return(xn);
}

void
submark(int *xmark, int *pxn, float x, struct xy *p)
{
	if (1.001 * p->xlb < x && .999 * p->xub > x)
		xmark[(*pxn)++] = log10(x) * p->xa + p->xb;
}

void
plot(void)
{
	int ix, iy;
	int i;
	int conn;

	conn = 0;
	if (mode != 0)
		pl_linemod(modes[mode]);
	for (i = 0; i < n; i++) {
		if (!conv(xx[i].xv, &xd, &ix) ||
		    !conv(xx[i].yv, &yd, &iy)) {
			conn = 0;
			continue;
		}
		if (mode != 0) {
			if (conn != 0)
				pl_cont(ix, iy);
			else
				pl_move(ix, iy);
			conn = 1;
		}
		conn &= symbol(ix, iy, xx[i].lblptr);
	}
	pl_linemod(modes[1]);
}

int
conv(float xv, register struct xy *p, int *ip)
{
	long ix;
	ix = p->xa * (*p->xf)(xv * p->xmult) + p->xb;
	if (ix < p->xbot || ix > p->xtop)
		return(0);
	*ip = ix;
	return(1);
}

int
getfloat(float *p)
{
	register int i;

	i = scanf("%f", p);
	return(i == 1);
}

int
getstring(void)
{
	register int i;
	char junk[20];
	i = scanf("%1s", labbuf);
	if (i == -1)
		return(-1);
	switch (*labbuf) {
	default:
		if (!isdigit(*labbuf)) {
			ungetc(*labbuf, stdin);
			i = scanf("%s", labbuf);
			break;
		}
	case '.':
	case '+':
	case '-':
		ungetc(*labbuf, stdin);
		return(0);
	case '"':
		i = scanf("%[^\"\n]", labbuf);
		scanf("%[\"]", junk);
		break;
	}
	if (i == -1)
		return(-1);
	return(strlen(labbuf));
}

int
symbol(int ix, int iy, int k)
{
	if (symbf == 0 && k < 0) {
		if (mode == 0)
			pl_point(ix, iy);
		return(1);
	}else {
		pl_move(ix, iy);
		pl_label(k >= 0 ? labs_ + k : plotsymb);
		pl_move(ix, iy);
		return(!brkf | (k < 0));
	}
}

void
title(void)
{
	pl_move(xd.xbot, yd.xbot - 60);
	if (titlebuf[0]) {
		pl_label(titlebuf);
		pl_label("       ");
	}
	if (gridf) {
		axlab('x', &xd);
		pl_label("  ");
		axlab('y', &yd);
	}
}

void
axlab(char c, struct xy *p)
{
	char buf[50];
	sprintf(buf, "%g -%s%c- %g", p->xlb / p->xmult,
		p->xf == log10 ? "log " : "", c, p->xub / p->xmult);
	pl_label(buf);
}

void
badarg(void)
{
	fprintf(stderr, "graph: error in arguments\n");
	exit(1);
}
