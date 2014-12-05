#!/bin/bash
rm program  &> /dev/null
NUM=$1
if [ $# -eq 0 ]
then
	echo "usage ./build.sh <problem number> <solution number> <-i or --info>"
	exit 1	
elif [ $# -eq 2 ] && [ "$2" == "-i" ] && [ "$2" == "--info" ]
then
	gcc p$1/a$2.c -g calc.c -o program -lm
	./program
fi
gcc p$1/a1.c -g calc.c -o program -lm
./program
while [ "$1" != "" ]; do
    case $1 in
        -i | --info )           shift
                                xdg-open https://projecteuler.net/problem=$NUM &> /dev/null &
								PS=$!
                                ;;
    esac
    shift
done
