#include "song.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>


Song* makeSong(char* _Name,char* _Artist,float _Duration){
    Song* temp = (Song *) malloc(sizeof(Song));
    temp->name= (char *) malloc(strlen(_Name)+1);
    //assert(temp->name!=NULL);
    strcpy(temp->name,_Name);
    temp->Artist= (char *) malloc(strlen(_Artist)+1);
    //assert(temp->Artist!=NULL);
    strcpy(temp->Artist,_Artist);
    temp->Duration=_Duration;
    return temp;
}