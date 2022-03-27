
find_bits: find_bits.o functions.o
	gcc -ansi -Wall -pedantic find_bits.o functions.o -o find_bits

find_bits.o: find_bits.c functions.h
	gcc -c -ansi -Wall -pedantic find_bits.c -o find_bits.o

functions.o: functions.c functions.h
	gcc -c -ansi -Wall -pedantic functions.c -o functions.o
