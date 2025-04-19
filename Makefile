CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: library

library: main.o book.o
	$(CC) $(CFLAGS) -o library main.o book.o

main.o: main.c book.h
	$(CC) $(CFLAGS) -c main.c

book.o: book.c book.h
	$(CC) $(CFLAGS) -c book.c

clean:
	rm -f *.o library
