compargs=gcc -Wall -pedantic

all: 1 2 3


1: ./1/main.c ./1/my_dll.h ./1/node.h my_dll.o node.o
	$(compargs) my_dll.o node.o ./1/main.c -o q1.out
	rm -f my_dll.o
	rm -f node.o

my_dll.o: ./1/my_dll.c ./1/my_dll.h ./1/node.h
	$(compargs) -c  ./1/my_dll.c > my_dll.o

node.o: ./1/node.h ./1/node.c
	$(compargs) -c ./1/node.c > node.o

2: ./2/complex.h ./2/main.c	complex.o
	$(compargs) complex.o ./2/main.c -o q2.out -lm
	rm -f complex.o

complex.o: ./2/complex.c ./2/complex.h
	$(compargs) -c ./2/complex.c > complex.o

3: ./3/user.h ./3/musicplayer.h ./3/song.h user.o musicplayer.o song.o ./3/main.c
	$(compargs) user.o musicplayer.o song.o ./3/main.c -o q3.out
	rm -f user.o
	rm -f musicplayer.o
	rm -f song.o

user.o: ./3/user.h ./3/user.c ./3/musicplayer.h ./3/song.h
	$(compargs) -c ./3/user.c > user.o

musicplayer.o: ./3/song.h ./3/musicplayer.h ./3/musicplayer.c
	$(compargs) -c ./3/musicplayer.c > musicplayer.o

song.o: ./3/song.c ./3/song.h
	$(compargs) -c ./3/song.c > song.o