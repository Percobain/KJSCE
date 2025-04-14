#!/bin/bash

echo "Enter first file name" 
read f1 
echo "Enter second file name" 
read f2 
if cmp -s "$f1" "$f2"; then
	echo "Files are same"
else
	echo "Files are different"
fi