single : single_list.o test_single_list.o
	gcc -o single single_list.o test_single_list.o

single_list.o : single_list.c single_list.h
	gcc -c single_list.c

test_single_list.o : test_single_list.c
	gcc -c test_single_list.c

clean : 
	rm single_list.o test_single_list.o single