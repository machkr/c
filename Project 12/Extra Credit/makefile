stack_client:stack_client.o stack.o
	gcc -o stackclient stack_client.o stack.o
stack_client.o:stack_client.c stack.h
	gcc -c stack_client.c
stack.o:stack.c stack.h
	gcc -c stack.c