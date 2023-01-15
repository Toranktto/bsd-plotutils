pl_label(s) char *s;
{
  register i, c;
  putch(037); /* alpha mode */
  for (i = 0; c = s[i]; i++)
    putch(c);
}
