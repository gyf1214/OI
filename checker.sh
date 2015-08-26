#!/bin/bash

g++ -x c++ -o checker checker.cpp
for ((i=1;i<=9;i++)) do
cp $1$i.in $1.in
./checker
cp $1.out $1$i.out
done
rm $1.in
rm $2.out
