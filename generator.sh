#!/bin/bash

g++ -x c++ -o generator generator.cpp
for ((i=1;i<=9;i++)) do
./generator $i > $1$i.in;
done
rm $i.in
rm $i.out
