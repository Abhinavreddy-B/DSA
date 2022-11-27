#ifndef _music_player_h_
#define _music_player_h_
#include "song.h"

typedef struct SongNode SongNode;
typedef struct MusicPlayer MusicPlayer;

struct SongNode{
    Song* song_details;
    struct SongNode* Next;
};

struct MusicPlayer{
    Song* curr_song;
    SongNode* QueueHead;
};

MusicPlayer* createMusicPlayer(void);
int addSongToQueue(MusicPlayer* _player,Song* _new_song);
int removeSongFromQueue(MusicPlayer* _player,int _pos);
int playSong(MusicPlayer* _player);
Song* getCurrentSong(MusicPlayer* _player);

#endif