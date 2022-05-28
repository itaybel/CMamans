OBJS = linked_list.o lists_c.o
lists_c: $(OBJS)
	gcc -ansi -Wall -pedantic $(OBJS) -o lists_c

lists_c.o: lists_c.c
	gcc -c -ansi -Wall -pedantic lists_c.c -o lists_c.o

linked_list.o: linked_list.c linked_list.h
	gcc -c -ansi -Wall -pedantic linked_list.c -o linked_list.o
clean:
	rm -f $(OBJS) lists_c