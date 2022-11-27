#include "user.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

User* createUser(char* _user_name){
    //printf("%s\n",_user_name);
    User* temp=(User *) malloc(sizeof(User));
    //assert(temp!=NULL);

    //if users want created succesfully
    if(!temp||!_user_name){
        return NULL;
    }

    temp->name=(char *) malloc(sizeof(strlen(_user_name)+1));
    strcpy(temp->name,_user_name);
    //assert(temp->name!=NULL);
    temp->LikedSongs=NULL;
    temp->user_music_player=NULL;
    return temp;
}

int addSongToQueueUser(User* _u, Song* _s){
    if(!_u||!_s){
        return 1;
    }

    //create a music player for user if he doesnt have any
    if(!_u->user_music_player){
        _u->user_music_player=createMusicPlayer();
    }
    addSongToQueue(_u->user_music_player,_s);
    return 0;
}

int removeSongFromQueueUser(User* _u,int _pos){
    if(!_u||!_u->user_music_player){
        return 1;
    }
    return removeSongFromQueue(_u->user_music_player,_pos);
}

int playSongUser(User* _u){
    if(!_u||!_u->user_music_player){
        return 1;
    }
    return playSong(_u->user_music_player);
}

Song* getCurrentSongUser(User* _u){
    printf("%p\n%p",_u);
    if(_u->user_music_player==NULL){
        return NULL;
    }
    return _u->user_music_player->curr_song;
}

int addLikedSong(User* _u, Song* _s){
    //printf("%s\n%s\n",_u->name,_s->name);
    if(!_u||!_s){
        return 1;
    }
    //printf("%p\n",_u->LikedSongs);
    /*if(_u->LikedSongs==NULL){
        _u->LikedSongs=(LikedList *) malloc(sizeof(LikedList));
    }*/
    LikedList* iterator=_u->LikedSongs;
    while(iterator){

        //comparing the 2 songs
        if(iterator->liked_song==_s){
            return 1;
        }
        iterator=iterator->Next;
    }
    //printf("%p\n",(void *) _u->LikedSongs);
    LikedList* temp;
    temp=(LikedList*)malloc(sizeof(LikedList));

    //adding temp to the front of the list for easy implementation
    temp->Next=_u->LikedSongs;
    temp->liked_song=_s;
    _u->LikedSongs=temp;
    iterator=_u->LikedSongs;
    //printf("%p\n",(void *) temp->Next);
    //printf("%s %s",temp->liked_song->name,temp->liked_song->Artist);
    return 0;
}

int removeLikedSong(User* _u,Song* _s){
    //printf("user index - %s\nsong index - %s\n",_u->name,_s->name);
    if(!_u||!_u->LikedSongs){
        return 1;
    }
    if(_u->LikedSongs->liked_song==_s){
            //printf("Entered\n");
            //printf("%p\n",_u->LikedSongs);
        free(_u->LikedSongs);
            //printf("%p\n",_u->LikedSongs);
        _u->LikedSongs=NULL;
        return 0;
    }
    LikedList* iterator=_u->LikedSongs;
    while(iterator->Next){
        if(iterator->Next->liked_song==_s){
            LikedList* temp=iterator->Next;
            iterator->Next=iterator->Next->Next;
            free(temp);
            return 0;
        }
        iterator=iterator->Next;
    }
    return 0;
}


int userCompatibility(User* _u1,User* _u2){
    //printf("%p\n%p\n",_u1,_u2);
    LikedList* it1=_u1->LikedSongs;
    LikedList* it2=_u2->LikedSongs;
    while(it1){
        //printf("%s\n",it1->liked_song->name);
        it1=it1->Next;
    }
    it1=_u1->LikedSongs;
    while(it2){
        //printf("%s\n",it2->liked_song->name);
        it2=it2->Next;
    }
    it2=_u2->LikedSongs;
    int count=0;
    while(it1){
        it2=_u2->LikedSongs;
        //printf("from abhinav - %s\n",it1->liked_song->name);
        while(it2){
            //printf("from gnana - %s\n",it2->liked_song->name);
            if(it1->liked_song==it2->liked_song){
                //printf("%d\n",count);
                count++;
                //printf("%d\n",count);
                break;
            }
            it2=it2->Next;
        }
        it1=it1->Next;
    }
    return count;
}