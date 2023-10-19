#!/bin/bash

a=0
b=1
sum=0

echo "Enter number :"
read N

for((i=0; i<N; i++))
do
	sum=$((sum+b))
	b=$((a+b))
	a=$((b-a))
done
 
echo "Total Sum of N Fibbonacci numbers are is: $sum" 
