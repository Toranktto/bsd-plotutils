#include <stdio.h>

float deltx;
float delty;
int PlotRes;

main(argc, argv) int argc;
char *argv[];
{
  int std = 1;
  char *progname;
  FILE *fin;

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
      case 'r':
        PlotRes = atoi(&argv[0][2]);
        break;
      }
      continue;
    }
    std = 0;
    fin = fopen(argv[0], "r");
    if (fin == NULL) {
      fprintf(stderr, "%s: can't open %s\n", progname, argv[0]);
      exit(1);
    }
    fplt(fin);
    fclose(fin);
  }
  if (std)
    fplt(stdin);
  exit(0);
}

fplt(fin) FILE *fin;
{
  register int c;
  char s[256];
  int xi, yi, x0, y0, x1, y1, r, dx, n, i;
  int pat[256];

  pl_open();
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
      getstr(s, fin);
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
      getstr(s, fin);
      pl_linemod(s);
      break;
    case 'd':
      xi = getsi(fin);
      yi = getsi(fin);
      dx = getsi(fin);
      n = getsi(fin);
      for (i = 0; i < n; i++)
        pat[i] = getsi(fin);
      pl_dot(xi, yi, dx, n, pat);
      break;
    }
  }
  pl_close();
}

/* get an integer stored in 2 ascii bytes. */
getsi(fin) register FILE *fin;
{
  short a, b;

  if ((b = getc(fin)) == EOF)
    return (EOF);
  if ((a = getc(fin)) == EOF)
    return (EOF);
  a = a << 8;
  return (a | b);
}

getstr(s, fin) register char *s;
register FILE *fin;
{

  for (; *s = getc(fin); s++)
    if (*s == '\n')
      break;
  *s = '\0';
}
