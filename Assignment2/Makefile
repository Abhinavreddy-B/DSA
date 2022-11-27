
compiler = gcc
compileflags = -Wall -pedantic -g3

all: 1 2 3 4


1: 1.c stack.o
	$(compiler) $(compileflags) 1.c stack.o -o 1 


2: 2.c deque.o queue.o
	$(compiler) $(compileflags) queue.o deque.o 2.c -o 2


3: 3.c stack.o
	$(compiler) $(compileflags) 3.c stack.o -o 3 


4: 4.c stack.o
	$(compiler) $(compileflags) 4.c stack.o -o 4


stack.o: stack.c stack.h ElementType.h
	$(compiler) $(compileflags) -c stack.c

main: main.c deque.o
	$(compiler) $(compileflags) main.c deque.o -o main

deque.o: deque.c deque.h ElementType.h
	$(compiler) $(compileflags) -c deque.c


queue.o: queue.c queue.h ElementType.h
	$(compiler) $(compileflags) -c queue.c

