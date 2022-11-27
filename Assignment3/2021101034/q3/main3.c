#include <stdio.h>
#include "hash.h"
#include <string.h>
int main(){
    struct HashTable* temp=init_hash_table(7,3,5);
    char inp[30];
    while(scanf("%s",inp)!=EOF){
        if(strcmp(inp,"INSERT")==0){
            int key;
            scanf("%d",&key);
            insert(temp,key);
        }else if(strcmp(inp,"REMOVE")==0){
            int key;
            scanf("%d",&key);
            delete(temp,key);
        }else if(strcmp(inp,"SEARCH")==0){
            int key;
            scanf("%d",&key);
            printf("%d\n",search(temp,key));
        }else if(strcmp(inp,"PRINT")==0){
            print_table(temp);
        }
    }
}