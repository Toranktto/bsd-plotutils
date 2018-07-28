#	@(#)Makefile	4.17 (Berkeley) 6/24/90

PROGS=	tek t4013 bgplot crtplot dumbplot gigiplot \
	hp7221plot implot atoplot plottoa grnplot
SCRIPTS=	plot.sh
SRCS=	atoplot.c chrtab.c crtdriver.c crtplot.c debug.c driver.c plottoa.c
BINDIR=	/usr/local/bin
MANDIR=	/usr/local/man/man
MAN=	plot.1

LDFLAGS= -L../libplot/bitgraph -L../libplot/dumb -L../libplot/gigi -L../libplot/vt0 \
		-L../libplot/hp7221/ -L../libplot/grn -L../libplot/t4014 -L../libplot/t4013 -L../libplot/imagen \
		-L../libplot/plot

all: ${PROGS} ${MAN}

atoplot: atoplot.c
	${CC} ${CFLAGS} -o ${.TARGET} ${.CURDIR}/atoplot.c ${LDFLAGS} -lplot -lm -lcompat

bgplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} -lplotbg -lm -lcompat

crtplot: crtdriver.o crtplot.o
	${CC} ${CFLAGS} -o ${.TARGET} crtdriver.o crtplot.o ${LDFLAGS} -lcurses \
	    -ltermcap -lm -lcompat

debug:
	${CC} ${CFLAGS} -o ${.TARGET} debug.c

dumbplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} -lplotdumb -ltermcap \
	    -lm -lcompat

gigiplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} -lplotgigi -lm -lcompat

grnplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} -lplotgrn -lm -lcompat

hp7221plot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} -lplot7221 -lm -lcompat

implot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} -lplotimagen -lm -lcompat

plottoa: plottoa.c
	${CC} ${CFLAGS} -o ${.TARGET} ${.CURDIR}/plottoa.c -Llib

t4013: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} -l4013 -lm -lcompat

tek: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} -l4014 -lm -lcompat

clean:
	rm -rf ${PROGS} ${SRCS:.c=.o} ${MAN:=.gz} debug

install: maninstall
	mkdir -p /usr/local/libexec/plot

	install ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${PROGS} \
	    /usr/local/libexec/plot
	install -c -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${.CURDIR}/plot.sh \
	    ${DESTDIR}${BINDIR}/plot

.include <bsd.prog.mk>
