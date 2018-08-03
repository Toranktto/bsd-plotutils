#	@(#)Makefile	4.17 (Berkeley) 6/24/90

PROGS=	tekplot t4013plot bgplot crtplot dumbplot gigiplot \
	hp7221plot implot grnplot plottoa atoplot plottoc
SRCS=	atoplot.c driver.c plottoa.c plottoc.c
MAN=	plot.1
MLINKS=	plot.1 bgplot.1 \
		plot.1 crtplot.1 \
		plot.1 dumbplot.1 \
		plot.1 gigiplot.1 \
		plot.1 grnplot.1 \
		plot.1 hp7221plot.1 \
		plot.1 implot.1 \
		plot.1 t4013plot.1 \
		plot.1 tekplot.1 \
		plot.1 plottoa.1 \
		plot.1 atoplot.1 \
		plot.1 plottoc.1
LDADD=	-L../libplot/bitgraph -L../libplot/dumb -L../libplot/gigi -L../libplot/vt0 \
		-L../libplot/hp7221/ -L../libplot/grn -L../libplot/t4014 -L../libplot/t4013 -L../libplot/imagen \
		-L../libplot/plot -L../libplot/crt -L/usr/local/lib
CFLAGS+=	-I../libplot/plot -I/usr/local/include
CSTD=c99
PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

all: ${PROGS} ${MAN}

atoplot: atoplot.c
	${CC} ${CFLAGS} -o ${.TARGET} atoplot.c ${LDFLAGS} ${LDADD} -lplot -lm

bgplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotbg -lm

crtdriver.o:
	$(CC) $(CFLAGS) -D__crtplot -c driver.c -o crtdriver.o

crtplot: crtdriver.o
	${CC} ${CFLAGS} -o ${.TARGET} crtdriver.o ${LDFLAGS} ${LDADD} -lcurses -ltermcap -lm -lplotcrt

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
	${CC} ${CFLAGS} -o ${.TARGET} plottoa.c ${LDFLAGS} ${LDADD}

plottoc: plottoc.c
	${CC} ${CFLAGS} -o ${.TARGET} plottoc.c ${LDFLAGS} ${LDADD}

t4013plot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplot4013 -lm

tekplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplot4014 -lm

clean:
	rm -rf ${PROGS} ${SRCS:.c=.o} ${MAN:=.gz} crtdriver.o

install: maninstall
	install ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${PROGS} \
	    ${DESTDIR}${BINDIR}
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} plot.sh \
	    ${DESTDIR}${BINDIR}/plot

.include <bsd.prog.mk>
