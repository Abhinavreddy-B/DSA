compargs = gcc -g3 -Wall -pedantic

main: complex.o main.c
	$(compargs) complex.o main.c -lm -o main

complex.o: complex.h complex.c
	$(compargs) -c complex.c > complex.o