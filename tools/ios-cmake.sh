#!/bin/sh
mkdir -p build.ios
cd build.ios
cmake -DCMAKE_TOOLCHAIN_FILE=../tools/ios-cmake/toolchain/iOS.cmake -DCMAKE_BUILD_TYPE=Release -GXcode ..
xcodebuild -configuration Release
