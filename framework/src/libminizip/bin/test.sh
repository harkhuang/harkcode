#!/bin/bash
echo '##### make libminizip.so test_minizip #####'
make -C../build/linux auto
echo '##### make libminizip.so test_minizip over#####'
echo '##### run test_minizip ######'
./test_minizip
