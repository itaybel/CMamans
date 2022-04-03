my_scalar: my_scalar.o functions.o
	gcc -ansi -Wall -pedantic my_scalar.o functions.o -o my_scalar

my_scalar.o: my_scalar.c functions.h
	gcc -c -ansi -Wall -pedantic my_scalar.c -o my_scalar.o

functions.o: functions.c functions.h
	gcc -c -ansi -Wall -pedantic functions.c -o functions.o
