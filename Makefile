all: main.c cartas21.o
	gcc main.c cartas21.o -o jogo21

cartas21.o: cartas21.c cartas21.h
	gcc cartas21.c -c
	
