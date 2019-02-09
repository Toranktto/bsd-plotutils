PLOT_PROGS=	tekplot t4013plot bgplot crtplot dumbplot gigiplot hp7221plot implot
PROGS=	plottoa atoplot
SRCS=	atoplot.c driver.c plottoa.c
MAN=	plot.1
MLINKS=	plot.1 plottoa.1 \
		plot.1 atoplot.1
LDADD=	-L../libplot/bitgraph -L../libplot/dumb -L../libplot/gigi -L../libplot/hp7221/ \
		-L../libplot/t4014 -L../libplot/t4013 -L../libplot/imagen \
		-L../libplot/plot -L../libplot/crt -L${LIBDIR}
CFLAGS+=	-I../libplot/plot -I${INCLUDEDIR}
CSTD=c99
PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include
LIBEXECDIR=	${PREFIX}/libexec
INSTALL=	../scripts/install-fakeroot.sh
MINSTALL=	../scripts/install-fakeroot.sh

all: ${PLOT_PROGS} ${PROGS} ${MAN}

atoplot: atoplot.c
	${CC} ${CFLAGS} -o ${.TARGET} atoplot.c ${LDFLAGS} ${LDADD} -lplot

bgplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotbg

crtdriver.o:
	$(CC) $(CFLAGS) -D__crtplot -c driver.c -o crtdriver.o

crtplot: crtdriver.o
	${CC} ${CFLAGS} -o ${.TARGET} crtdriver.o ${LDFLAGS} ${LDADD} -lplotcrt

dumbplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotdumb

gigiplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotgigi

hp7221plot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplot7221

implot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplotimagen

plottoa: plottoa.c
	${CC} ${CFLAGS} -o ${.TARGET} plottoa.c ${LDFLAGS} ${LDADD}

t4013plot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplot4013

tekplot: driver.o
	${CC} ${CFLAGS} -o ${.TARGET} driver.o ${LDFLAGS} ${LDADD} -lplot4014

clean:
	rm -rf ${PROGS} ${PLOT_PROGS} ${SRCS:.c=.o} ${MAN:=.gz} crtdriver.o

install: maninstall
	${INSTALL} ${STRIP} -m ${BINMODE} ${PLOT_PROGS} \
	    ${DESTDIR}${LIBEXECDIR}
	${INSTALL} ${STRIP} -m ${BINMODE} ${PROGS} \
	    ${DESTDIR}${BINDIR}
	${INSTALL} -c -m ${BINMODE} plot.sh \
	    ${DESTDIR}${BINDIR}/plot

.include <bsd.prog.mk>
