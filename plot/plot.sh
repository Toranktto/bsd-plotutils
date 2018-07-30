#!/bin/sh
#	@(#)plot.sh	4.6	(Berkeley)	7/24/89
#
PATH=/usr/local/libexec/plot
case $1 in
-T*)	t=$1
	shift ;;
*)	t=-T$TERM
esac
case $t in
-Ttek4014|-Ttek|-T4014|-T)	exec tek "$@" ;;
-T4013)			exec t4013 "$@" ;;
-Tbitgraph|-Tbg)	exec bgplot "$@";;
-Tgigi|-Tvt125)		exec gigiplot "$@";;
-Thp|-T2648|-T2648a|-Thp2648|-Thp2648a|h8)
			exec hpplot "$@";;
-Tip|-Timagen)		exec implot "$@";;
-Tgrn)			exec grnplot "$@";;
-Tcrt)			exec crtplot "$@";;
-Tdumb|un|unknown)	exec dumbplot "$@";;
*)  			exec crtplot "$@";;
esac
