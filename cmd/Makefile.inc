CFLAGS+=	-I${.CURDIR}/../../lib/plot

PLOT_LIBS!=  realpath ${.CURDIR}/../../lib/*/
.for lib in ${PLOT_LIBS}
LDADD+= -L${lib}
.endfor

.include "../Makefile.inc"