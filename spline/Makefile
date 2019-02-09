#	@(#)Makefile	5.2 (Berkeley) 5/11/90

PROG=	spline
MAN=	spline.1
CFLAGS+=	-I../libplot/plot -I${INCLUDEDIR}
LDADD=	-L${LIBDIR}

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
