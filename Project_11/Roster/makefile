roster: readline.o player.o roster.o
	gcc -o roster readline.o player.o roster.o

readline.o: readline.c readline.h
	gcc -c readline.c

player.o: player.c player.h readline.h
	gcc -c player.c 

roster.o: roster.c player.h
	gcc -c roster.c

