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

ARGS="$@"

if [ "`whoami`" = "root" ]; then
	# Check if user is fake root by creating file with random name in / directory.
	# It's not 100% correct, but should be enough.
	RANDOM=`head -200 /dev/urandom | cksum | cut -f1 -d " "`
	touch /$RANDOM > /dev/null 2>&1

	# Fake root don't have permissions (exit code 1) to change file owner to real root
	# so remove owner and group arguments.
	if [ $? -eq 1 ]; then
		ARGS=`echo "$ARGS" | sed -e "s/-o [a-zA-Z0-9_]*//g"`
		ARGS=`echo "$ARGS" | sed -e "s/-g [a-zA-Z0-9_]*//g"`
		ARGS=`echo "$ARGS" | sed -e "s/--owner=[a-zA-Z0-9_]*//g"`
		ARGS=`echo "$ARGS" | sed -e "s/--group=[a-zA-Z0-9_]*//g"`	
	else
		rm -rf /$RANDOM
	fi
fi

install $ARGS
