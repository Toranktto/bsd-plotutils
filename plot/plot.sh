#!/bin/sh
#	@(#)plot.sh	4.6	(Berkeley)	7/24/89
#

PATH=/bin:/usr/bin:/usr/local/bin

xplot() {
	TMP=`mktemp /tmp/plot.XXXXXX`
	dd if=/dev/stdin of="$TMP" status=none
	xterm -t -e "env PATH=\"$PATH\" sh -c \"tekplot \"$@\" < \"$TMP\";while [ 1 ];do sleep 999;done\""
	rm -f $TMP
}

case $1 in
-T*)	t=$1
	shift ;;
*)	t=-T$TERM
esac
case $t in
-Ttek4014|-Ttek|-T4014)	exec tekplot "$@" ;;
-T4013)			exec t4013plot "$@" ;;
-Tbitgraph|-Tbg)	exec bgplot "$@" ;;
-Tgigi|-Tvt125)		exec gigiplot "$@" ;;
-Thp7221|-Thp7|-Th7)	exec hp7221plot "$@" ;;
-Tip|-Timagen)		exec implot "$@" ;;
-Tgrn)			exec grnplot "$@" ;;
-Tdumb|-Tun|-Tunknown)	exec dumbplot "$@" ;;
-TX)		xplot "$@" ;;
*)  			exec crtplot "$@" ;;
esac
