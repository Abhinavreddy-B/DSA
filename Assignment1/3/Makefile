compargs = gcc -g3 -Wall -pedantic

main:	musicplayer.o song.o user.o main.c
	$(compargs) musicplayer.o song.o user.o main.c -o main


user.o:	user.c musicplayer.h song.h user.h
	gcc -c user.c > user.o

musicplayer.o:	musicplayer.c musicplayer.h song.h
	gcc -c musicplayer.c > musicplayer.o

song.o: song.c song.h
	gcc -c song.c > song.o