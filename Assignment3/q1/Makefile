Compilerargs= -g3 -Wall -pedantic

main: tree.o
	gcc $(Compilerargs) main.c tree.o queue.o treenode.o -o main

tree.o: tree.h treenode.o queue.o Elementtype.h tree.c
	gcc -c $(Compilerargs) tree.c

Elementtype.h: treenode.h

treenode.o: treenode.h treenode.c
	gcc -c $(Compilerargs) treenode.c

queue.o: queue.c Elementtype.h queue.h
	gcc -c $(Compilerargs) queue.c