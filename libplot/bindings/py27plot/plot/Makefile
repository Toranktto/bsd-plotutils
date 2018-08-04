#	@(#)Makefile	5.3 (Berkeley) 5/11/90

LIB=	py27plot
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c module.c
CFLAGS+=	-I../../../plot -I${INCLUDEDIR} -I${INCLUDEDIR}/python2.7
LDADD=	-L../../../plot -L${REAL_LIBDIR} -lplot -lpython2.7
CSTD=c99
SHLIB_MAJOR=	1
SHLIB_MINOR=	0
PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
REAL_LIBDIR=	${PREFIX}/lib
LIBDIR=	${REAL_LIBDIR}/python2.7/site-packages
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

install: maninstall
	install ${STRIP} -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} lib${LIB}.so \
	    ${DESTDIR}${LIBDIR}/${LIB}.so

.include <bsd.lib.mk>
