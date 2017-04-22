#!/bin/bash
clear
gcc -o out shanks.c  -lm

./out $1

echo ""
echo "-------------------FIN------------------------"
rm out