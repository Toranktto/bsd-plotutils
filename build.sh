#!/usr/bin/env sh
set -e
cd "$(cd -P -- "$(dirname -- "$0")" && pwd -P)"

PREFIX=/opt/bsd-plotutils
CONFIG=Release
BUILD_DIR=build

usage() {
  echo "Usage:"
  echo "  $0 [-h]             show this help message"
  echo "  $0 [-s] [-d] [-r]   build package"
  echo "Flags:"
  echo "  -h  Show this help message"
  echo "  -d  Build and/or package dynamic-linking libraries"
  echo "  -s  Build and/or package static-linking libraries"
  echo "  -z  When -s is present, include static binaries in the package"
  echo "  -x  When -z is present, don't include libraries in the package"
  echo "  -p  Create package"
  echo "  -n  When -p is present, don't build, just create package"
  echo "  -r  When -p is present, use latest git tag as version"
}

[ $# -eq 0 ] && (usage; exit 1)

LINK_BINARIES=SHARED
while getopts "dsrhzxpn" arg; do
  case "$arg" in
  r)
    RELEASE=YES
    ;;
  s)
    BUILD_STATIC=YES
    ;;
  d)
    BUILD_SHARED=YES
    ;;
  z)
    LINK_BINARIES=STATIC
    ;;
  x)
    NO_LIBS_INCLUDE=YES
    ;;
  p)
    PACKAGE=YES
    ;;
  n)
    NO_BUILD=YES
    ;;
  h)
    usage
    exit 0
    ;;
  *)
    usage
    exit 1
    ;;
  esac
done

if [ -z "$BUILD_SHARED" ] && [ -z "$BUILD_STATIC" ]; then
  echo "Error: must specify at least one of -s or -d"
  exit 1
fi

if [ -z "$BUILD_STATIC" ] && [ "$LINK_BINARIES" = "STATIC" ]; then
  if [ ! -d "build/static" ]; then
      echo "Error: cannot link binaries statically when static libraries are not built"
      echo "       (run first with -s)"
      exit 1
  fi
fi

if [ -z "$BUILD_SHARED" ] && [ "$LINK_BINARIES" = "SHARED" ]; then
  echo "Error: cannot link binaries dynamically when packaging only static libraries"
  echo "       (use -z to link binaries statically)"
  exit 1
fi

if [ "$NO_LIBS_INCLUDE" = "YES" ] && [ "$LINK_BINARIES" = "SHARED" ]; then
  echo "Error: cannot link dynamically, when packaging only binaries"
  echo "       (use -z to link binaries statically)"
  exit 1
fi

if [ "$RELEASE" = "YES" ] && [ -z "$PACKAGE" ]; then
  echo "Error: -r can only be used with -p"
  exit 1
fi

if [ "$NO_BUILD" = "YES" ] && [ -z "$PACKAGE" ]; then
  echo "Error: -n can only be used with -p"
  exit 1
fi

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

build() {
  cmake "$1" -D CMAKE_INSTALL_PREFIX="$PREFIX" -S ../.. -B .
  cmake --build . --config $CONFIG
  rm -rf pkg
  mkdir -p pkg
  cmake --install . --prefix "pkg$PREFIX" --strip --config $CONFIG
}

if [ "$BUILD_STATIC" = "YES" ]; then
  if [ "$NO_BUILD" = "YES" ]; then
    if [ ! -d "static" ]; then
      echo "Error: cannot create package without static libraries"
      echo "       (run first with -s)"
      exit 1
    fi
  else
    echo "Building static..."
    mkdir -p static
    cd static
    build -DBUILD_SHARED_LIBS=NO
    cd ..
  fi
fi

if [ "$BUILD_SHARED" = "YES" ]; then
  if [ "$NO_BUILD" = "YES" ]; then
    if [ ! -d "shared" ]; then
      echo "Error: cannot create package without shared libraries"
      echo "       (run first with -d)"
      exit 1
    fi
  else
    echo "Building shared..."
    mkdir -p shared
    cd shared
    build -DBUILD_SHARED_LIBS=YES
    cd ..
  fi
fi

rm -rf pkg
mkdir -p pkg

case $LINK_BINARIES in
"SHARED")
  cp -rv shared/pkg/. pkg
  if [ -z "$NO_LIBS_INCLUDE" ] && [ "$BUILD_STATIC" = "YES" ]; then
      cp -vn static/pkg$PREFIX/lib/* pkg$PREFIX/lib
  fi
  ;;
"STATIC")
  cp -rv static/pkg/. pkg
  if [ -z "$NO_LIBS_INCLUDE" ] && [ "$BUILD_SHARED" = "YES" ]; then
    cp -vn shared/pkg$PREFIX/lib/* pkg$PREFIX/lib
  fi
  ;;
esac

if [ "$NO_LIBS_INCLUDE" = "YES" ]; then
  rm -rf pkg$PREFIX/lib
  rm -rf pkg$PREFIX/include
  rm -rf pkg$PREFIX/share/man/man3
  rm -rf pkg$PREFIX/share/man/man5
fi

cd pkg
tar -zcvf dist.tar.gz ".$PREFIX"
cd ../..
mkdir -p dist

if [ "$PACKAGE" = "YES" ]; then
  DIST_NAME="bsd-plotutils"

  if [ "$RELEASE" = "YES" ]; then
    DIST_NAME="$DIST_NAME-v$(git describe --tags "$(git rev-list --tags --max-count=1)")"
  else
    DIST_NAME="$DIST_NAME-$(git rev-parse --short HEAD)"
  fi

  DIST_NAME="$DIST_NAME-$(uname -sm | tr ' ' '-' | tr '[:upper:]' '[:lower:]')"

  if [ -z "$NO_LIBS_INCLUDE" ]; then
    [ "$BUILD_STATIC" = "YES" ] && DIST_NAME="$DIST_NAME-staticlib"
    [ "$BUILD_SHARED" = "YES" ] && DIST_NAME="$DIST_NAME-sharedlib"
  fi
  [ "$LINK_BINARIES" = "STATIC" ] && DIST_NAME="$DIST_NAME-staticbin"
  [ "$LINK_BINARIES" = "SHARED" ] && DIST_NAME="$DIST_NAME-sharedbin"

  mv -v $BUILD_DIR/pkg/dist.tar.gz dist/"$DIST_NAME.tar.gz"
  rm -rf $BUILD_DIR/pkg
fi
