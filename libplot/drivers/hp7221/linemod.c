#include "hp7221.h"

void pl_linemod(char *line) {
  /*
   * Note that the bit patterns could be compacted using the
   *  repeat field conventions.  They aren't for clarity.
   *  Examples of almost identical packed patterns are in the
   *  comments.
   *  If pl_linemod( is changed really often, a ~15% savings
   *  could be achieved.
   */
  if (*(line) == 's') {
    if (*(++line) == 'o') {
      /*
       * solid mode 1
       */
      printf("vA");
      return;
    } else if (*(line) == 'h') {
      /*
       * shortdashed mode 4
       */
      printf("vD");
      return;
    }
  } else if (*(line) == 'd') {
    if (*(++line) == 'o' && *(++line) == 't') {
      if (*(++line) == 't') {
        /*
         * dotted mode 2
         *  printf( "W(P00001)" );
         */
        printf("vB");
        return;
      } else if (*(line) == 'd') {
        /*
         * dotdashed mode 3
         *  printf( "W(P0110010)" );
         */
        printf("vC");
        return;
      }
    }
  } else if (*(line) == 'l') {
    /*
     * longdashed mode 5
     *  printf( "W(P11100)" );
     */
    printf("vE");
    return;
  }
  printf("vA");
  return;
}
