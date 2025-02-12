# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror

# Default target to build the Jeopardy game
all: jeopardy

# Link object files to create the executable
jeopardy: main.o game.o player.o question.o
	$(CC) -o jeopardy main.o game.o player.o question.o

# Compilation rules for source files
main.o: main.c game.h player.h question.h game_data.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h game_data.h
	$(CC) $(CFLAGS) -c game.c

player.o: player.c player.h game_data.h
	$(CC) $(CFLAGS) -c player.c

question.o: question.c question.h game_data.h
	$(CC) $(CFLAGS) -c question.c

