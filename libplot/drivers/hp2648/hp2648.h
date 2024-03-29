/*
 * Displays plot files on an hp2648a graphics terminals.  I have heard
 * that all hp plotting devices use the same control sequences, so this
 * might work for all hp devices capable of plotting.
 */

#include <fcntl.h>
#include <math.h>
#include <plot.h>
#include <sgtty.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TERMINAL "/dev/tty"

#define ENQ 05
#define ACK 06
#define ESC 033
#define GRAPHIC '*'
#define MODE 'm'
#define PLOT 'p'
#define DISPLAY 'd'
#define PENUP 'a'
#define BINARY 'i'
#define CR '\n'

#define TRUE 1
#define FALSE 0

#define xsc(xi) ((int)(xi - lowx) * scalex + 0.5)
#define ysc(yi) ((int)(yi - lowy) * scaley + 0.5)

extern int shakehands;
extern int currentx;
extern int currenty;
extern int buffcount;
extern int fildes;
extern float lowx;
extern float lowy;
extern float scalex;
extern float scaley;
extern struct sgttyb sarg;
void handshake(void);
void buffready(int n);
void itoa(int num, char *byte1, char *byte2);
