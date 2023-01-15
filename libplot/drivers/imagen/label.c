#include "imPcodes.h"
#include "imp.h"
extern int imPcsize;
void pl_label(char *s) {
  register int i, c;
  putch(imP_SET_ABS_H);
  putwd((int)((imPx - obotx) * scalex + botx) - imPcsize / 2);
  putch(imP_SET_ABS_V);
  putwd((int)((imPy - oboty) * scaley + boty - (imPcsize / 1.6)));
  for (i = 0; (c = s[i]); i++) {
    imPx += imPcsize / scalex;
    putch((c == ' ') ? imP_SP : c);
  }
}
