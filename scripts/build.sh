#!/usr/bin/env bash
set -e

SDK_DIR="3rdparty/smrcore_sdk"
ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd -P)"

cd "$ROOT_DIR"

if [ ! -f "$SDK_DIR/lib/cmake/smrcore_sdk/smrcore_sdkConfig.cmake" ]; then
    echo "SDK not found at ${SDK_DIR}; running ./scripts/download.sh"
    ./scripts/download.sh
fi

cmake -S examples -B build -DCMAKE_PREFIX_PATH="$ROOT_DIR/$SDK_DIR"
cmake --build build

echo "Done: ${ROOT_DIR}/build"
