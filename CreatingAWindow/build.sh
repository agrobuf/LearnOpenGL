#!/bin/bash

# Exit on the first error
set -e

echo "Beginning Cmake"
# cmake -S . -B ./build -DCMAKE_TOOLCHAIN_FILE="../Environment/build/Release/generators/conan_toolchain.cmake"
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release

echo "Beginning Make"
make -C ./build/
