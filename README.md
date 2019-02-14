# BSD plotutils

Traditional plotting utilities and libraries taken from 4.3BSD with some improvements.  
Original libraries were written in C, but there are bindings to other languages:
  * `py27plot` (Python 2.7)
  * `f77plot` (FORTRAN 77)

It's **not** compatible with old `libplot` due to conflicts with curses library, but if
compatibility is really needed, there is a `plotcompat.h` header.

## Overview
`libplot` is library that implements plotting routines in device-independent manner.  

## Installation from source

You need BSD make and makefile templates (`bmake` package on Ubuntu).  
```
# make && make install
```
Default installation prefix is `/usr/local` on FreeBSD and `/usr` on everything else.  
If some language bindings are not needed, remove right entries
from Makefile in [libplot/bindings/](libplot/bindings/.) directory.  

On some GNU/Linux distributions bmake must be manually patched to work correctly.  
(https://diego.assencio.com/?index=26abaf6aa4fd450564a038d599bb7f5c) and `STRIP`
makefile variable must be set to "-s" or "" via command line when installing:
```
# bmake STRIP="-s" install
```
