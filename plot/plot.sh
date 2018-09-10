#!/bin/sh
#	@(#)plot.sh	4.6	(Berkeley)	7/24/89
#

PATH=/bin:/usr/bin:/usr/local/bin

xplot() {
	TMP=`mktemp /tmp/plot.XXXXXX`
	tekplot "$@" > "$TMP"

	if [ "$?" -eq 0 ]; then
		xterm -t -e "sh -c \"cat \"$TMP\";while [ 1 ];do sleep 1;done\""
	fi

	rm -f $TMP
}

case $1 in
-T*)	t=$1
	shift ;;
*)	t=-T$TERM
esac

case $t in
-Ttek4014|-Ttek|-T4014)	exec tekplot "$@" ;;
-T4013)				exec t4013plot "$@" ;;
-Tbitgraph|-Tbg)	exec bgplot "$@" ;;
-Tgigi|-Tvt125)		exec gigiplot "$@" ;;
-Thp7221|-Thp7|-Th7)	exec hp7221plot "$@" ;;
-Tip|-Timagen)		exec implot "$@" ;;
-Tgrn)				exec grnplot "$@" ;;
-Tcrt)				exec crtplot "$@" ;;
-TX)	xplot "$@" ;;
*)					exec dumbplot "$@" ;;
esac
