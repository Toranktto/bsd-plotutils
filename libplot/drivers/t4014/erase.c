extern int ohiy;
extern int ohix;
extern int oloy;
extern int oextra;
pl_erase() {
  int i;
  putch(033);
  putch(014);
  ohiy = -1;
  ohix = -1;
  oextra = -1;
  oloy = -1;
  return;
}
