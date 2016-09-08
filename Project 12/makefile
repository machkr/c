readline.o: readline.c
	gcc -c readline.c

player.o: player.c
	gcc -c player.c

roster.o: roster.c
	gcc -c roster.c

roster: readline.o player.o roster.o
	gcc -o roster readline.o player.o roster.o