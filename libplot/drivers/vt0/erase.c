extern vti;
pl_erase() {
  int i;
  i = 0401;
  write(vti, &i, 2);
}
