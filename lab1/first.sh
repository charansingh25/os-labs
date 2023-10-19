#!/bin/bash

echo "Enter first number"
read a

echo "Enter second number"
read b

echo "Before swapping a : $a and b : $b"

a=$((a+b))
b=$((a-b))
a=$((a-b))
echo "After swapping a : $a and b : $b"
