booltest: booltest.o boolean.o
	gcc -o booltest booltest.o boolean.o

booltest.o: booltest.c boolean.h
	gcc -c booltest.c

boolean.o: boolean.c boolean.h
	gcc -c boolean.c
