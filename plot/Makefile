#	@(#)Makefile	4.17 (Berkeley) 6/24/90

PROGS=	tek t4013 bgplot crtplot dumbplot gigiplot \
	hp7221plot implot atoplot plottoa grnplot
SCRIPTS=	plot.sh
SRCS=	atoplot.c chrtab.c crtdriver.c crtplot.c debug.c driver.c plottoa.c
MAN=	plot.1
LDADD= -L../libplot/bitgraph -L../libplot/dumb -L../libplot/gigi -L../libplot/vt0 \
		-L../libplot/hp7221/ -L../libplot/grn -L../libplot/t4014 -L../libplot/t4013 -L../libplot/imagen \
		-L../libplot/plot
PREFIX=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

all: ${PROGS} ${MAN}

atoplot: atoplot.c
	${CC} ${CFLAGS} -o ${.TARGET} ${.CURDIR}/atoplot.c ${LDFLAGS} ${LDADD} -lplot -lm

bgplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotbg -lm

crtplot: crtdriver.o crtplot.o
	${CC} ${CFLAGS} -o ${.TARGET} crtdriver.o crtplot.o ${LDFLAGS} ${LDADD} -lcurses -ltermcap -lm

debug:
	${CC} ${CFLAGS} -o ${.TARGET} debug.c

dumbplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotdumb -ltermcap -lm

gigiplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotgigi -lm

grnplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotgrn -lm

hp7221plot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplot7221 -lm

implot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotimagen -lm

plottoa: plottoa.c
	${CC} ${CFLAGS} -o ${.TARGET} ${.CURDIR}/plottoa.c ${LDFLAGS} ${LDADD}

t4013: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -l4013 -lm

tek: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -l4014 -lm

clean:
	rm -rf ${PROGS} ${SRCS:.c=.o} ${MAN:=.gz} debug

install: maninstall
	mkdir -p /usr/local/libexec/plot

	install ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${PROGS} \
	    ${DESTDIR}/usr/local/libexec/plot
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} plot.sh \
	    ${DESTDIR}${BINDIR}/plot

.include <bsd.prog.mk>
