#	@(#)Makefile	5.6 (Berkeley) 5/11/90

LIB=	plotimagen
# DEFRES == default printer resolution dpi
CFLAGS+=-DDEFRES=240
SRCS=	arc.c box.c charset.c circle.c close.c cont.c dot.c \
	erase.c label.c line.c linemod.c move.c open.c point.c \
	scale.c space.c
CFLAGS+=	-I../plot -I${INCLUDEDIR}
LDADD=	-L${LIBDIR} -lm
CSTD=c99
SHLIB_MAJOR=	1
SHLIB_MINOR=	0

BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
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

INSTALL=	../../install-fixed.sh
MINSTALL=	../../install-fixed.sh

.include <bsd.lib.mk>
