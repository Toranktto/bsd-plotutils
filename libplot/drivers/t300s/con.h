#include <math.h>
#include <plot.h>
#include <sgtty.h>
#include <stdio.h>
#include <stdlib.h>

/* gsi plotting output routines */
#define DOUBLE 010
#define ADDR 0100
#define COM 060
#define PENUP 04
#define MAXX 070
#define MAXY 07
#define SPACES 7
#define DOWN 012
#define UP 013
#define LEFT 010
#define RIGHT 040
#define BEL 007
#define ESC 033
#define ACK 006
#define INPLOT 'P'
#define CR 015
#define FF 014
#define VERTRESP 48
#define HORZRESP 60.
#define VERTRES 8.
#define HORZRES 6.
/* down is line feed, up is reverse line feed,
   left is backspace, right is space.  48 points per inch
   vertically, 60 horizontally */

extern int xnow, ynow;
extern int OUTF;
extern struct sgttyb ITTY, PTTY;
extern float HEIGHT, WIDTH, OFFSET;
extern int xscale, xoffset, yscale;
extern float botx, boty, obotx, oboty, scalex, scaley;

int xconv(int xp);
int yconv(int yp);
void spew(int ch);
void inplot(void);
void outplot(void);
void tobotleft(void);
void reset(void);
float dist2(int x1, int y1, int x2, int y2);
void swap(int *pa, int *pb);
void movep(int xg, int yg);
int xsc(int xi);
int ysc(int yi);
