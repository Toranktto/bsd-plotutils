void frame(int n) {
  extern int vti;
  n = (n & 0377) | 02000;
  write(vti, &n, 2);
}
