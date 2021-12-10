CC = gcc
CFLAGS = -Wall
all: board.o conway.o
	$(CC) $^ -o conway.out

%.o: %.c board.h
	$(CC) -c $<

clean:
	rm *.o
