#!/usr/bin/env sh
set -e
cd "$(cd -P -- "$(dirname -- "$0")" && pwd -P)"

./build.sh -ds

./build.sh -dspnr   # sharedlib + staticlib + sharedbin
./build.sh -dszpnr  # sharedlib + staticlib + staticbin
./build.sh -dszxpnr # staticbin
./build.sh -szpnr   # staticlib + staticbin
./build.sh -dpnr    # sharedlib + sharedbin
./build.sh -dzpnr   # sharedlib + staticbin
