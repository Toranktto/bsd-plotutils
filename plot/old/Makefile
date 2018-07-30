#	@(#)Makefile	4.17 (Berkeley) 6/24/90

PROG=	crtplot_old
SRCS=	crtdriver.c crtplot.c
CSTD=c99
MAN=
LDADD=	-lcurses -ltermcap -lm
PREFIX=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include

install: maninstall
	mkdir -p ${DESTDIR}${PREFIX}/libexec/plot

	install ${STRIP} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${PROG} \
	    ${DESTDIR}${PREFIX}/libexec/plot

.include <bsd.prog.mk>
