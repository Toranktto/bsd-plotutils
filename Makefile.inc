CFLAGS+=    -std=iso9899:1999 -Werror -O3
PREFIX?=	/usr/local
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
MANDIR=	${PREFIX}/man
FILESDIR=	${PREFIX}/share/misc
INCLUDEDIR=	${PREFIX}/include
LIBEXECDIR=	${PREFIX}/libexec
.if ${PREFIX} == "/usr"
MANDIR=	${PREFIX}/share/man
.endif
