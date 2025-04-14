#!/bin/bash

if [ "$#" -ne 1 ] || ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Usage: $0 <integer>"
    exit 1
fi

num=$1
factorial=1

for (( i=1; i<=num; i++ )); do
    factorial=$((factorial * i))
done

echo "Factorial of $num is $factorial."