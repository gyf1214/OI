#!/bin/bash

chmod +x ./$1
echo $1
echo
for ((i = 1; i <= $2; i++))
do
	cp $1$i.in $1.in
	echo $i
	date +开始%t%S:%N
	./$1
	date +结束%t%S:%N
	echo 
	diff -b $1.out $1$i.out
	rm $1.in
done
