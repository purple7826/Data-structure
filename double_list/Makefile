double : double_list.o test_double_list.o
	gcc -o double double_list.o test_double_list.o

double_list.o : double_list.c double_list.h
	gcc -c double_list.c

test_double_list.o : test_double_list.c
	gcc -c test_double_list.c

clean :
	rm test_double_list.o double_list.o double