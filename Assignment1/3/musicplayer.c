#include "musicplayer.h"
#include <stdlib.h>

MusicPlayer* createMusicPlayer(void){
    MusicPlayer* temp = (MusicPlayer*) malloc(sizeof(MusicPlayer));
    temp->curr_song=NULL;
    temp->QueueHead=NULL;
    return temp;
}

int addSongToQueue(MusicPlayer* _player,Song* _new_song){
    
    //when song does not exist
    if(_new_song==NULL) return 1;

    //iterator for the queue
    SongNode* iterator=_player->QueueHead;

    //case when player is not present yet
    if(!_player->QueueHead){
        _player->QueueHead=(SongNode*) malloc(sizeof(SongNode));
        
        //if memory is not alocated properly
        if(!_player->QueueHead){
            return 1;
        }


        _player->QueueHead->song_details=_new_song;
        _player->QueueHead->Next=NULL;
        return 0;
    }

    //reach the end of the queue
    while(iterator->Next){
        iterator=iterator->Next;
    }

    //allocating memory for new Node
    iterator->Next=(SongNode*) malloc(sizeof(SongNode));
    
    //if memory could not be initalised
    if(!iterator->Next){
            return 1;
    }

    iterator->Next->song_details=_new_song;
    iterator->Next->Next=NULL;
    return 0;
}

int removeSongFromQueue(MusicPlayer* _player,int _pos){
    
    //iterator
    SongNode* iterator=_player->QueueHead;
    
    //if the player queue is empty
    if(iterator==NULL||_pos<0){
        return 1;
    }

    //base case when only 1 song is present
    if(_pos==0&&iterator!=NULL){
        _player->QueueHead=_player->QueueHead->Next;
        free(iterator);
        return 0;
    }

    //just to keep track of current position
    int count=0;

    //reach the previous node
    while(iterator->Next){

        //reach the previous node
        if(count==_pos-1){
            SongNode* temp=iterator->Next;
            iterator->Next=iterator->Next->Next;
            free(temp);
            return 0;
        }
        count++;
    }

    //if pos is >= the total elements
    return 1;
}


int playSong(MusicPlayer* _player){
    //if _player is not even created
    if(!_player){
        return 1;
    }

    //if _player does not have any song in queue
    if(_player->QueueHead==NULL){
        return 1;
    }

    //if the song does not exist ( by some fault )
    if(_player->QueueHead->song_details==NULL){
        return 1;
    }
    SongNode* temp=_player->QueueHead;
    _player->curr_song=_player->QueueHead->song_details;
    _player->QueueHead=_player->QueueHead->Next;
    free(temp);
    return 0;
}

Song* getCurrentSong(MusicPlayer* _player){
    return _player->curr_song;
}