/*
 * Displays plot files on an HP7221 plotter.
 * Cloned from bgplot.c and gigiplot.c by Jim Kleckner
 * Thu Jun 30 13:35:04 PDT 1983
 *  Requires a handshaking program such as hp7221cat to get
 *  the plotter open and ready.
 */

#include "hp7221.h"
#include <signal.h>

int currentx = 0;
int currenty = 0;
double lowx = 0.0;
double lowy = 0.0;
double scale = 1.0;

void pl_open(void) {
  /* catch interupts */
  signal(SIGINT, (void (*)(int))pl_close);
  currentx = 0;
  currenty = 0;
  printf("~VR~W");
  putMBP(800, 2000);
  putMBP(7600, 9600);
  printf("~S");
  putMBP(XMAX, YMAX);
  printf("vA~*z");

  pl_space(0, 0, XMAX, YMAX);
}
