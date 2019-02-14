#!/bin/sh
#
# Copyright (c) 2018 Łukasz Derlatka
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#

if [ "$#" -eq 0 ]; then
	echo "usage: $0 <submodules>"
	exit 1
fi

SUBMODULES="$@"

for m in $SUBMODULES; do
	if [ -d "$m" ]; then
		echo "===> $m (skipping)"
		continue
	elif [ -f "$m" ]; then
		echo "===> $m"
		rm -rf "$m"
	else
		echo "===> $m"
	fi

	mkdir -p "$m"
	cd "$m"

	for f in ../plot/*; do
		if [ "`basename $f`" = "`basename $0`" ]; then
			continue
		fi

		if [ -f "$f" ] && [ "`basename $f`" = "module.c" ] || [ "`basename $f`" = "Makefile" ]; then
			data=""
			case "$m" in
				"bitgraph")
					data=`cat $f | sed -e "s/py27plot/py27plotbg/g" | sed -e "s/-lplot/-lplotbg/g"`
					;;
				"t4013")
					data=`cat $f | sed -e "s/py27plot/py27plot4013/g" | sed -e "s/-lplot/-lplot4013/g"`
					;;
				"hp7221")
					data=`cat $f | sed -e "s/py27plot/py27plot7221/g" | sed -e "s/-lplot/-lplot7221/g"`
					;;
				"t4014")
					data=`cat $f | sed -e "s/py27plot/py27plot4014/g" | sed -e "s/-lplot/-lplot4014/g"`
					;;
				*)
					data=`cat $f | sed -e "s/py27plot/py27plot$m/g" | sed -e "s/-lplot/-lplot$m/g"`
					;;
			esac

			data=`echo "$data" | sed -e "s/-L..\/..\/..\/plot/-L..\/..\/..\/$m/g"`
			echo "$data" > ./`basename $f`
			echo "$f -> ./`basename $f`"
		else
			cp -r $f ./`basename $f`
			echo "$f -> ./`basename $f`"
		fi
	done

	cd ..
done
