extern int vti;
void pl_circle(int x, int y, int r) {
  char c;
  c = 5;
  write(vti, &c, 1);
  write(vti, &x, 6);
}
