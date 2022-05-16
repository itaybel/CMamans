
OBJS = mainmat.o commands.o input.o mat.o errors.o
my_mat: $(OBJS)
	gcc -g -ansi -Wall -pedantic $(OBJS) -o my_mat


mainmat.o: mainmat.c header.h 
	gcc -c -ansi -Wall -pedantic mainmat.c -o mainmat.o

commands.o: commands.c commands.h
	gcc -c -ansi -Wall -pedantic commands.c -o commands.o

input.o: input.c input.h 
	gcc -c -ansi -Wall -pedantic input.c -o input.o
	
mat.o: mat.h mat.c
	gcc -c -ansi -Wall -pedantic mat.c -o mat.o
	
errors.o: errors.h errors.c
	gcc -c -ansi -Wall -pedantic errors.c -o errors.o


clean:
	rm -f $(OBJS) my_mat
