Compilerargs= -g3 -Wall -pedantic

main1: tree.o
	gcc $(Compilerargs) main1.c tree.o queue.o treenode.o -o main1

tree.o: tree.h treenode.o queue.o Elementtype.h tree.c
	gcc -c $(Compilerargs) tree.c

Elementtype.h: treenode.h

treenode.o: treenode.h treenode.c
	gcc -c $(Compilerargs) treenode.c

queue.o: queue.c Elementtype.h queue.h
	gcc -c $(Compilerargs) queue.c