#ifndef _PLOT_H
#define _PLOT_H 1

void openpl(void);
void erase(void);
void label(char *s);
void line(int x1, int y1, int x2, int y2);
void circle(int x, int y, int r);
void arc(int x, int y, int x0, int y0, int x1, int y1);
void move(int x, int y);
void cont(int x, int y);
void point(int x, int y);
void linemod(char *s);
void space(int x0, int y0, int x1, int y1);
void closepl(void);
void dot(int xi, int yi, int dx, int n, int pat[]);
void box(int x0, int y0, int x1, int y1);

#endif