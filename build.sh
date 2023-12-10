#!/usr/bin/env bash

if [ -f min ]; then
    rm -f main
fi

gcc main.c func.c -o main -lm

./main
