#	@(#)Makefile	5.3 (Berkeley) 5/11/90

LIB=	py27plot
SHLIB_NAME=	${LIB}.so.${SHLIB_MAJOR}
SRCS=	arc.c box.c circle.c close.c cont.c dot.c erase.c label.c \
	line.c linemod.c move.c open.c point.c space.c module.c
CFLAGS+=	-I../../../plot -I${INCLUDEDIR} -I${INCLUDEDIR}/python2.7
LDADD=	-L../../../plot -L${REAL_LIBDIR} -lplot -lpython2.7
CSTD=c99
SHLIB_MAJOR=	1
SHLIB_MINOR=	0

BINDIR=	${PREFIX}/bin
REAL_LIBDIR=	${PREFIX}/lib
LIBDIR=	${REAL_LIBDIR}/python2.7/site-packages
MANDIR=	${PREFIX}/share/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

UNAME_S!=	uname -s
.if ${UNAME_S} == "FreeBSD"
PREFIX?=	/usr/local
.else
PREFIX?=	/usr
.endif

.if ${PREFIX} == "/usr/local"
MANDIR=	${PREFIX}/man/man
.endif

INSTALL=	../../../../install-fixed.sh
MINSTALL=	../../../../install-fixed.sh

install: maninstall
	mkdir -p ${DESTDIR}${LIBDIR}
	${INSTALL} ${STRIP} -o ${LIBOWN} -g ${LIBGRP} -m ${LIBMODE} lib${LIB}.so \
	    ${DESTDIR}${LIBDIR}/${LIB}.so

.include <bsd.lib.mk>
