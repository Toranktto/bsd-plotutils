extern int vti;
void pl_erase(void) {
  int i;
  i = 0401;
  write(vti, &i, 2);
}
