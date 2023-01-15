#!/usr/bin/env sh
PATH="$(cd -P -- "$(dirname -- "$0")" && pwd -P)/../libexec/plot:$PATH"

usage() {
	echo 1>&2 "usage: $(basename "$0") -Tdriver [...]"
	exit 1
}

[ $# -eq 0 ] && usage

DRIVER="$1"
shift

case "$DRIVER" in
-T450)
  shift;
  exec t450 "$@"
  ;;
-T300)
  exec t300 "$@"
  ;;
-T300S|-T300s)
  exec t300s "$@"
  ;;
-Tver)
  exec vplot "$@"
  ;;
-Ttek|-T4014|-T)
  exec tek "$@"
  ;;
-T4013)
  exec t4013 "$@"
  ;;
-Tbitgraph|-Tbg)
  exec bgplot "$@"
  ;;
-Tgigi|-Tvt125)
  exec gigiplot "$@"
  ;;
-Taed)
  exec aedplot "$@"
  ;;
-Thp7221|-Thp7|-Th7)
  exec hp7221plot "$@"
  ;;
-Thp|-T2648|-T2648a|-Thp2648|-Thp2648a|-Th8)
  exec hpplot "$@"
  ;;
-Tip|-Timagen)
  exec implot "$@"
  ;;
-Tdumb|-Tun|-Tunknown|-Tascii)
  exec dumbplot "$@"
  ;;
-Tcrt)
  dumbplot "$@" | more
  ;;
-T*)
  echo 1>&2 "plot: unknown driver: ${DRIVER#-T}"
  exit 2
  ;;
*)
  usage
  ;;
esac
