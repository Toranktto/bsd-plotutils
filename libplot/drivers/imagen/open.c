#include "imPcodes.h"
#include "imp.h"
void setfont(char *c, int sz) {
  imPcsize = sz;
  putch(imP_CREATE_FAMILY_TABLE);
  putch(2);
  putch(1);
  putch(0);
  fprintf(stdout, "%s", c);
  putch(0);
}
void pl_open(void) {

  putch(imP_SET_HV_SYSTEM);
  putch((3 << 3) | 5);
  putch(imP_SET_FAMILY);
  putch(2);
  setfont(imP_charset, imPcsize);
  putch(imP_SET_IL);
  putwd(imPcsize + 3);
  putch(imP_SET_SP);
  putwd(imPcsize);
  putch(imP_SET_PEN);
  putch(2);
  putch(imP_SET_ABS_H);
  putwd(0);
  putch(imP_SET_ABS_V);
  putwd(0);
}
