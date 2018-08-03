#ifndef lint
static char sccsid[] = "@(#)driver.c	4.4 (Berkeley) 9/21/85";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <plot.h>
#include <unistd.h>
#include <string.h>
#ifdef __crtplot
#include <signal.h>
#endif

float deltx;
float delty;

void fplt(FILE *fin);
int getsi(register FILE *fin);
void getstr(register char *s, register FILE *fin, int len);
#ifdef __crtplot
void winresize(void);
#endif

int
main(int argc, char *argv[])
{
	int std = 1;
	char *progname;
	FILE *fin;

#ifdef __crtplot
	if (!isatty(fileno(stdout))) {
		fprintf(stderr, "crtplot: output must be a terminal\n");
		exit(1);
	}

	signal(SIGWINCH, (__sighandler_t*)winresize);
#endif

	progname = argv[0];
	for (argc--, argv++; argc > 0; argc--, argv++) {
		if (argv[0][0] == '-') {
			switch (argv[0][1]) {
			case 'l':
				deltx = atoi(&argv[0][2]) - 1;
				break;
			case 'w':
				delty = atoi(&argv[0][2]) - 1;
				break;
			}
			continue;
		}
		std = 0;
		fin = fopen(argv[0], "r");
		if (fin == NULL) {
			fprintf(stderr, "%s: can't open %s\n", progname,
				argv[0]);
			exit(1);
		}

		fplt(fin);
		fclose(fin);
	}

	if (std) {
#ifdef __crtplot
		if (isatty(fileno(stdin))) {
			fprintf(stderr, "crtplot: input cannot be a terminal\n");
			exit(1);
		}
#endif
		fplt(stdin);
	}

	exit(0);
}

void
fplt(FILE *fin)
{
	register int c;
	char s[256];
	int xi, yi, x0, y0, x1, y1, r;
#ifndef __crtplot
	int dx, n, i;
	int *pat;
	unsigned int pat_len = 256;

	pat = malloc(pat_len * sizeof(int));
#endif

	pl_openpl();
	while ((c = getc(fin)) != EOF) {
		switch (c) {
		case 'm':
			xi = getsi(fin);
			yi = getsi(fin);
			pl_move(xi, yi);
			break;
		case 'l':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			pl_line(x0, y0, x1, y1);
			break;
		case 't':
			getstr(s, fin, 256);
			pl_label(s);
			break;
		case 'e':
			pl_erase();
			break;
		case 'p':
			xi = getsi(fin);
			yi = getsi(fin);
			pl_point(xi, yi);
			break;
		case 'n':
			xi = getsi(fin);
			yi = getsi(fin);
			pl_cont(xi, yi);
			break;
		case 's':
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			pl_space(x0, y0, x1, y1);
			break;
		case 'a':
			xi = getsi(fin);
			yi = getsi(fin);
			x0 = getsi(fin);
			y0 = getsi(fin);
			x1 = getsi(fin);
			y1 = getsi(fin);
			pl_arc(xi, yi, x0, y0, x1, y1);
			break;
		case 'c':
			xi = getsi(fin);
			yi = getsi(fin);
			r = getsi(fin);
			pl_circle(xi, yi, r);
			break;
		case 'f':
			getstr(s, fin, 256);
			pl_linemod(s);
			break;
		case 'd':
#ifndef __crtplot
			xi = getsi(fin);
			yi = getsi(fin);
			dx = getsi(fin);
			n = getsi(fin);
			if (n > pat_len) {
				pat_len *= 2;
				pat = realloc(pat, pat_len * sizeof(int));
			}
			for (i = 0; i < n; i++)
				pat[i] = getsi(fin);
			pl_dot(xi, yi, dx, n, pat);
#endif
			break;
		}
	}
	pl_closepl();
#ifndef __crtplot
	free(pat);
#endif
}

/* get an integer stored in 2 ascii bytes. */
int
getsi(register FILE *fin)
{
	short a, b;

	if ((b = getc(fin)) == EOF)
		return(EOF);
	if ((a = getc(fin)) == EOF)
		return(EOF);
	a = a << 8;
	return(a | b);
}

void
getstr(register char *s, register FILE *fin, int len)
{
	unsigned int s_len;

	fgets(s, len, fin);
	/* Strip newline */
	s_len = strlen(s);
	if (s[s_len - 1] == '\n')
		s[s_len - 1] = '\0';
}

#ifdef __crtplot
void
winresize(void)
{
	signal(SIGWINCH, SIG_IGN);

	pl_closevt();
	exit(1);
}
#endif
