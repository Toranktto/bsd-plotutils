#	@(#)Makefile	4.6 (Berkeley) 5/11/90

PROG=	graph
LDADD=	-L../libplot/plot -L${LIBDIR} -lplot -lm
CFLAGS+=	-I../libplot/plot -I${INCLUDEDIR}
CSTD=c99
PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include
INSTALL=	../scripts/install-fakeroot.sh
MINSTALL=	../scripts/install-fakeroot.sh

.include <bsd.prog.mk>
