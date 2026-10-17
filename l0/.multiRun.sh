#!/bin/bash
prg="$1"
count="$2"
for ((i = 1; i <= count; i++)); do
    echo "iterasyon : $i"
    eval "$prg"
done
