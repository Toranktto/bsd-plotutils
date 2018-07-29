#ifndef lint
static char sccsid[] = "@(#)crtdriver.c	4.2 (Berkeley) 1/9/85";
#endif

/*
 * This driver is used with crtplot.c.
 * It is essentially the same driver as the one in /usr/src/cmd/plot.
 * Unfortunately, the curses library has some of the same names as does
 * as the functions that the driver calls.  These have been changed.
 *
 * Also, one of the commands has been removed since they don't make sense
 * for crt's.
 */


#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

float deltx;
float delty;

void getstr_(char *s, FILE *fin);
void fplt(FILE *fin);
int getsi(FILE *fin);

extern void openpl(void);
extern void closepl(void);
extern void plot_move(int x, int y);
extern void line(int x0, int y0, int x1, int y1);
extern void label(char *str);
extern void plot_erase(void);
extern void point(int x, int y);
extern void cont(int x, int y);
extern void linemod(char *string);
extern void circle(int xc, int yc,int r);
extern void arc(int xc, int yc, int xbeg, int ybeg, int xend, int yend);
extern void space(int x0, int y0, int x1, int y1);

int
main(int argc, char **argv)
{
	int std=1;
	FILE *fin;

	while(argc-- > 1) {
		if(*argv[1] == '-')
			switch(argv[1][1]) {
				case 'l':
					deltx = atoi(&argv[1][2]) - 1;
					break;
				case 'w':
					delty = atoi(&argv[1][2]) - 1;
					break;
			}
		else {
			std = 0;
			if ((fin = fopen(argv[1], "r")) == NULL) {
				fprintf(stderr, "can't open %s\n", argv[1]);
				exit(1);
			}
			fplt(fin);
		}
		argv++;
	}

	if (std) {
		/* fplt( stdin ); */
		fprintf(stderr, "stdin cannot be used with CRT driver\n");
		exit(1);
	}

	exit(0);
}

void
fplt(FILE *fin)
{
	int c;
	char s[256];
	int xi,yi,x0,y0,x1,y1,r/*,dx,n,i*/;
	/*int pat[256];*/

	openpl();
	while((c=getc(fin)) != EOF) {
		switch(c) {
		case 'm':
			xi = getsi(fin);
			yi = getsi(fin);
			plot_move(xi,yi);
			break;
		case 'l':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			line(x0,y0,x1,y1);
			break;
		case 't':
			getstr_(s,fin);
			label(s);
			break;
		case 'e':
			plot_erase();
			break;
		case 'p':
			xi = getsi(fin);
			yi = getsi(fin);
			point(xi,yi);
			break;
		case 'n':
			xi = getsi(fin);
			yi = getsi(fin);
			cont(xi,yi);
			break;
		case 's':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			space(x0,y0,x1,y1);
			break;
		case 'a':
			xi = getsi(fin);
			yi = getsi(fin);
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			arc(xi,yi,x0,y0,x1,y1);
			break;
		case 'c':
			xi = getsi(fin);
			yi = getsi(fin);
			r = getsi(fin);
			circle(xi,yi,r);
			break;
		case 'f':
			getstr_(s,fin);
			linemod(s);
			break;
		}
	}

	closepl();
}

/* get an integer stored in 2 ascii bytes. */
int
getsi(FILE *fin)
{
	short a, b;
	if((b = getc(fin)) == EOF)
		return(EOF);
	if((a = getc(fin)) == EOF)
		return(EOF);
	a = a<<8;
	return(a|b);
}

void
getstr_(char *s, FILE *fin)
{
	for( ; (*s = getc(fin)); s++)
		if(*s == '\n')
			break;
	*s = '\0';
}
