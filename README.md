# BSD plotutils

Standard UNIX plotting utilities ported from 4.3BSD (and partially from UNIX V7) to modern OSes.

## Why?

I initially ported these programs in 2018 to learn basics of the C language and UNIX.  
The current goal is to create a library and CLI tools to generate simple graphs in popular formats.

## Available drivers

### Historical

* aed — AED 512 color graphics terminal.
* bitgraph (aliases: bg) — BBN bitgraph terminal.
* hp7221 (aliases: hp7) — HP 7221 graphics terminal.
* hp2648 (aliases: hp, hp8) — HP 2648A graphics terminal.
* imagen (aliases: im) — Imagen laser printer (default 240 dots-per-inch resolution).
* t300 — DASI 300 or GSI terminal (Diablo mechanism).
* t300s — DASI 300S terminal (Diablo mechanism).
* t450 — DASI Hyterm 450 terminal (Diablo mechanism).
* t4013 — Tektronix 4013 storage scope.
* vt0 — DEC VT100 graphics terminal.
* gigi (aliases: vt125) — DEC VT125 graphics terminal.

### Modern

* t4014 (aliases: tek) — Tektronix 4014 or 4015 storage scope with Enhanced Graphics Module. It is available as XTerm
  mode (`xterm -t -tn tek4014`).
* dumb (aliases: ascii) — Simple ASCII output.

## Portability

This code was originally written in the pre-POSIX era and uses some non-portable features.
Platforms confirmed to work:

* Ubuntu 20.04 LTS x86_64
* FreeBSD 13.0-RELEASE amd64
* Darwin 22.2.0 arm64

Future code should conform to the C23 standard if possible.

## Backwards compatibility

Programs and libraries should be compatible with versions available in UNIX V7, 4.3BSD and System V
flavours (e.g. Solaris, AIX).   
Compatibility at the source code level can be achieved through the header `plotcompat.h`.  
Bugs compatibility is not guaranteed.

## Contents

This repository contains the `libplot` library with its drivers and programs (as well as manual pages for them):

* `plot` — reads plot in device-independent binary format and draws it on the device.
* `tplot` — alias to `plot` (for compatibility with SVR4 shell scripts).
* `graph` — reads points and draws plot in binary format.
* `vplot` — variant of `plot` that draws only on Versatec plotter (for compatibility with SVR4 shell scripts).
* `atoplot` — reads plot in text format and converts it to binary (useful for debugging).
* `plottoa` — reads plot in binary format and converts it to text (useful for debugging).
* `spline` — reads points and generates more via smooth curve interpolation.

## Building from source

You need POSIX-compatible shell and libraries, CMake >= 3.24 and a C compiler (Clang is preferred) with C23 support.

```
$ ./build.sh -dsp
```

This will build a tarball in the `dist` directory.
