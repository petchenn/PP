CC = g++
CFLAGS = -c -std=c++11

lab2.o: lab2.cpp Threads.h
 $(CC) $(CFLAGS) lab2.cpp

Threads.o: Threads.cpp Threads.h
 $(CC) $(CFLAGS) Threads.cpp

all: lab2.o Threads.o

clean:
 rm -f *.o
