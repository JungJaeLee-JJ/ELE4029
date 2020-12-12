#!bin/bash
echo "test"
make clean
make 
./scanner_cimpl ./test/test.1.txt > ./test/my_result.1.txt
./scanner_cimpl ./test/test.2.txt > ./test/my_result.2.txt
