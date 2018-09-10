# BSD plotutils

Traditional plotting utilities and libraries taken from 4.3BSD with some improvements. 
Original libraries were written in C, but there are bindings to other languages:
  * `py27plot` (Python 2.7)
  * `f77plot` (FORTRAN 77)

It's **not** compatible with ancient `libplot` due to conflicts with curses library, but if
compatibility is really needed, there is a `plotcompat.h` header.

## Overview
`libplot` is library that implements plotting routines in device-independent manner.  
Except this, there are some other libraries (with `libplot` prefix, for example `libplotcrt`) that implements routines in manner
specific to appropiate device. Device-independent file format is described in `plot(5)` and can be translated to machine-dependent plotting routines
(using `plot(1)`) and ASCII text (using `plottoa(1)`).
`graph(1)` is utility that converts pairs of numbers from standard input to device-independent plotting routines.

## Installation from source

You need BSD make and makefile templates. If you have, just run:
```
# make && make install && make cleandir
```
as root. Default installation prefix is `/usr/local`. If some language bindings are not needed, remove right entries
from Makefile in [libplot/bindings/](libplot/bindings/.) directory.

## Installation from binaries

Currently only **FreeBSD 11.2 amd64** packages are provided. 
Each release has *.txz file which is binary package. If you want to install, run:
```
pkg install <path_to_file.txz>
```
