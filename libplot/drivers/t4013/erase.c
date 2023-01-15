extern int ohiy;
extern int ohix;
extern int oloy;
pl_erase() {
  int i;
  putch(033);
  putch(014);
  ohiy = -1;
  ohix = -1;
  oloy = -1;
  return;
}
