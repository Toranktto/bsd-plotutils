#ifndef lint
static char sccsid[] = "@(#)driver.c	4.4 (Berkeley) 9/21/85";
#endif

#include <stdio.h>
#include <stdlib.h>
#include <plot.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <signal.h>

float deltx;
float delty;

static void fplt(FILE *fin);
static int getsi(register FILE *fin);
static void getstr(register char *s, register FILE *fin, int len);
#ifdef __crtplot
static void winresize(void);
#endif

int
main(int argc, char *argv[])
{
	int std = 1;
	FILE *fin;

	setprogname(argv[0]);
#ifdef __crtplot
	if (!isatty(fileno(stdout))) {
		fprintf(stderr, "%s: output must be a terminal\n", getprogname());
		exit(1);
	}

	signal(SIGWINCH, (__sighandler_t*)winresize);
#endif

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
			fprintf(stderr, "%s: can't open %s\n", getprogname(), argv[0]);
			exit(1);
		}

		fplt(fin);
		fclose(fin);
	}

	if (std) {
#ifdef __crtplot
		if (isatty(fileno(stdin))) {
			fprintf(stderr, "%s: input cannot be a terminal\n", getprogname());
			exit(1);
		}
#endif
		fplt(stdin);
	}

	exit(0);
}

static void
fplt(FILE *fin)
{
	register int c;
	char s[256];
	int xi, yi, x0, y0, x1, y1, r;
	int dx, n, i;
	int *pat;
	unsigned int pat_len = 256;

	pat = malloc(pat_len * sizeof(int));

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
			break;
		default:
			pl_closevt();
			fprintf(stderr, "%s: malformed input\n", getprogname());
			free(pat);
			exit(1);
		}
	}
	pl_closepl();
	free(pat);
}

/* get an integer. */
static int
getsi(register FILE *fin)
{
	int a;
	short b;

	fread(&b, sizeof(b), 1, fin);
	a = ntohs(b);

	return a;
}

static void
getstr(register char *s, register FILE *fin, int len)
{
	fgets(s, len, fin);
	s[strlen(s) - 1] = '\0';
}

#ifdef __crtplot
static void
winresize(void)
{
	signal(SIGWINCH, SIG_IGN);

	pl_closevt();
	fprintf(stderr, "%s: terminal resized\n", getprogname());
	exit(1);
}
#endif
