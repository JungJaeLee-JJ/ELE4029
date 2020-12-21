#!/bin/bash

git pull origin master
make clean
make
./cminus ./test/test.1.txt
