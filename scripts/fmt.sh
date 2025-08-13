#!/bin/sh

FILES=$(find src -type f -name '*.c')

clang-format -i $FILES
