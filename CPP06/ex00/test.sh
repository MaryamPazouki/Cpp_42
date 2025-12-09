#!/bin/bash

tests=(
a Z !
0 42 -42 +42 +0
0.0f 42.0f -42.5f
0.0 42.2 -42.42
nan nanf +inf -inf +inff -inff
2147483647 2147483648
999999999999999999999999999
33333330000000000000000000
2147483647 
0.0f
-0.0f
-0.0
hello 42ff 1.2.3 ++42 --42
)

for t in "${tests[@]}"
do
    echo "INPUT: $t"
    ./convert "$t"
    echo "----------------------"
done
