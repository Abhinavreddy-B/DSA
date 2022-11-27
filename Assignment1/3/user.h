#ifndef _user_H_
#define _user_H_

#include "musicplayer.h"

typedef struct _liked_list LikedList;
typedef struct User User;
struct _liked_list{
    Song* liked_song;
    struct _liked_list* Next;
};

struct User{
    char* name;
    MusicPlayer* user_music_player;
    LikedList* LikedSongs;
};

User* createUser(char* _user_name);

int addSongToQueueUser(User* _u, Song* _s);

int removeSongFromQueueUser(User* _u,int _pos);

int playSongUser(User* _u);

Song* getCurrentSongUser(User* _u);

int addLikedSong(User* _u, Song* _s);

int removeLikedSong(User* _u,Song* _s);

int userCompatibility(User* _u1,User* _u2);

#endif