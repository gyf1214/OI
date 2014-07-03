#!/bin/bash

mkdir $1
mkdir $1/src
mkdir $1/bin
echo //Created At: `date` >> $1/src/main.cpp
cat template.cpp >> $1/src/main.cpp


