# BSD plotutils
Standard UNIX plotting utilities ported from 4.4BSD with some improvements and removed obsolete backends.  

## Why?
I initially ported this program in 2018 to learn basics of the C language and UNIX.  
The current goal is to create an extremely simple library and CLI tools to generate graphs in popular formats such as SVG or even raw ASCII.  

## Available backends (formats)
Currently available backends in the library:
* tek4014 (aliases: t4014, tek) — Tektronix 4014 graphics terminal (Enhanced Graphics Mode). It is available as XTerm mode.
* ascii (aliases: dumb) — Simple ASCII-Art output.

## Portability
This code was originally written in the pre-POSIX era (around 1975 and modified in 1983) and uses BSD extensions for libc, as well as make.  
Platforms confirmed to work:
* Ubuntu 20.04 LTS x86_64
* FreeBSD 13.0-RELEASE amd64
  
The current and future code should conform to the C99 standard if possible.

## Backwards compatibility
CLI tools should be fully compatible with version available in 4.2BSD and System V Release 4, excluding support for most ancient plotters and terminals.  
Compatibility at the source code level is available through the header `plotcompat.h` instead of `plot.h`.  
Bugs compatibility is not guaranteed.

## Contents
This repository contains the `libplot` library and command line tools: `plot`, `atoplot`, `plottoa`, `graph` and `spline`, as well as manpages for them.
`vplot` is not available now, but may be in the future - as a tool that directly sends a graph to the printer daemon.

## Examples
```bash
$ cat << EOF | spline | graph -g 0 | plot -Tdumb
-10.0 10.0
-5.0 5.0
0.0 0.0
5.0 5.0
10.0 10.0
EOF
```

```
     *
      **                                                                                                       **
        **                                                                                                  ***
          ***                                                                                             **
             **                                                                                         **
               **                                                                                     **
                 **                                                                                 **
                   **                                                                             **
                     *                                                                           *
                      **                                                                      ***
                        ***                                                                 **
                           *                                                               *
                            **                                                           **
                              *                                                         *
                               *                                                       *
                                **                                                   **
                                  *                                                 *
                                   *                                               *
                                    **                                          ***
                                      **                                       *
                                        *                                     *
                                         *                                   *
                                          **                               **
                                            *                             *
                                             **                         **
                                               *                       *
                                                **                   **
                                                  **               **
                                                    ****       ****
                                                        *******
```

## Installation from source
You need BSD make (installed as `bmake` on Linux systems) and C99 compiler.  
Makefiles should be compatible between NetBSD and FreeBSD templates.
```
# make PREFIX=/opt/bsd-plotutils all hier install clean
```
