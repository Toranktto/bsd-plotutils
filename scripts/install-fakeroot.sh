#!/bin/sh

ARGS=`echo "$@" | sed -e "s/-o [a-zA-Z0-9_]*//g"`
ARGS=`echo "$ARGS" | sed -e "s/-g [a-zA-Z0-9_]*//g"`
ARGS=`echo "$ARGS" | sed -e "s/--owner=[a-zA-Z0-9_]*//g"`
ARGS=`echo "$ARGS" | sed -e "s/--group=[a-zA-Z0-9_]*//g"`
install $ARGS
