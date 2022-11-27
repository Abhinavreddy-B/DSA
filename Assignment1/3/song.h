#ifndef _SONG_H_
#define _SONG_H_

typedef struct Song Song;

//structure containing the details of a song
struct Song{
    char* name;
    char* Artist;
    float Duration;
};

//function to create a new song and return the pointer
Song* makeSong(char* _Name,char* _Artist,float _Duration);

#endif