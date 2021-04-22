#!/bin/bash

echo "compiling..."
gcc -c calcsum.c
gcc -c main.c
echo "obj files created"
gcc calcsum.o main.o  -o $1
echo "file type: "
file $1
