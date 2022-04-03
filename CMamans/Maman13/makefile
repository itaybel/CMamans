
lists_ab: mymat.o mat.o
	gcc -ansi -Wall -pedantic mymat.o mat.o -o mat

mat.o: mat.h mat.c
	gcc -c -ansi -Wall -pedantic mat.c -o mat.o

mymat.o: mat.h mymat.c 
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o
