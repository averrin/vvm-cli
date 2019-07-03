#!/usr/bin/env bash

clang++ ./main.cpp include/vvm-core/src/* include/vvm-core/deps/*.cc \
    -o vvm \
    -Iinclude/vvm-core/include \
    -Iinclude/vvm-core/deps \
    -std=c++17 -stdlib=libc++ -Wno-narrowing
