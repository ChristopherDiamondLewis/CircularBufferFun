CC = gcc

all: CircularBuffer.o main.o
		$(CC) CircularBuffer.o main.o -o CircularBufferDemo

CircularBuffer.o: CircularBuffer.c CircularBuffer.h
		$(CC) -c CircularBuffer.c

main.o: main.c CircularBuffer.h
		$(CC) -c main.c

clean:
		rm -f *.o CircularBufferDemo