PLOT_PROGS=	tek4014plot asciiplot
PROGS=	plottoa atoplot
SRCS=	atoplot.c driver.c plottoa.c
MAN=	plot.1
MLINKS=	plot.1 plottoa.1 \
		plot.1 atoplot.1
LDADD+=	-L ../../lib/plot -L ../../lib/tek4014 -L ../../lib/ascii
CFLAGS+=	-I ../../lib/plot
CSTD=c99

PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/share/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include
LIBEXECDIR=	${PREFIX}/libexec

all: ${PLOT_PROGS} ${PROGS} ${MAN}

atoplot: atoplot.c
	${CC} ${CFLAGS} -o ${.TARGET} atoplot.c ${LDFLAGS} ${LDADD} -lplot

plottoa: plottoa.c
	${CC} ${CFLAGS} -o ${.TARGET} plottoa.c ${LDFLAGS} ${LDADD}

asciiplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplot_ascii

tek4014plot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplot_tek4014

clean:
	rm -rf ${PROGS} ${PLOT_PROGS} ${SRCS:.c=.o} ${MAN:=.gz}

LIBEXECDIR_ESCAPED!=	echo ${LIBEXECDIR} | sed 's/\//\\\//g'

install: maninstall
	${INSTALL} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${PLOT_PROGS} \
	    ${DESTDIR}${LIBEXECDIR}
	${INSTALL} ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${PROGS} \
	    ${DESTDIR}${BINDIR}
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} plot.sh \
	    ${DESTDIR}${BINDIR}/plot
	sed -i "s/@LIBEXEC@/${LIBEXECDIR_ESCAPED}/g" ${DESTDIR}${BINDIR}/plot

.include <bsd.prog.mk>

# NetBSD make compatibility
.ifdef STRIPFLAG
STRIP=	${STRIPFLAG}
.endif