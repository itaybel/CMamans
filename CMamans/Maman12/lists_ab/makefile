
lists_ab: lists_ab.o functions.o
	gcc -ansi -Wall -pedantic lists_ab.o functions.o -o lists_ab

lists_ab.o: lists_ab.c functions.h
	gcc -c -ansi -Wall -pedantic lists_ab.c -o lists_ab.o

functions.o: functions.c functions.h
	gcc -c -ansi -Wall -pedantic functions.c -o functions.o
