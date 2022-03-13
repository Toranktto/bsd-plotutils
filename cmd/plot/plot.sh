#!/usr/bin/env sh
PATH=@LIBEXEC@:$PATH

args=`getopt T: $*`
if [ $? -ne 0 ]; then
	echo 1>&2 "usage: `basename $0` -T driver"
	exit 1
fi

set -- $args
while :; do
	case "$1" in
	-T)
		driver="$2"
		shift; shift
		;;
	--)
		shift; break
		;;
	esac
done

case "$driver" in
ascii|dumb|crt|un|unknown)
	exec asciiplot "$@"
	;;
tek4014|tek|4014|t4014)
	exec tek4014plot "$@"
	;;
*)
	echo 1>&2 "plot: invalid driver"
	exit 2
	;;
esac
