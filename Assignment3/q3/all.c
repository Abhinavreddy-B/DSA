#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

////////////////////////////////////hash.h
struct Item{
    int key;
    int frequency;
    struct Item* next;
};

struct Bucket{
    struct Item * items;
};

struct HashTable{
    int a,b,countBucket;
    struct Bucket* buckets;

    //(a*key+b)%countBucket
};

int getHash(struct HashTable* T,int key);

struct HashTable* init_hash_table(int a,int b,int countBucket);
struct HashTable* insert(struct HashTable* T,int key);
bool search(struct HashTable* T,int key);
struct HashTable* Delete(struct HashTable* T,int key);
void print_table(struct HashTable* T);
///////////////////////////////////////////////////


///////////////////////////////////////////////////main.c

int ins=0,del=0,srh=0;

int main(){
    struct HashTable* temp=init_hash_table(11,7,2);
    char inp[30];
    int ins_freq=0,del_freq=0,srh_freq=0;
    while(scanf("%s",inp)!=EOF){
        if(strcmp(inp,"INSERT")==0){
            int key;
            ins_freq++;
            scanf("%d",&key);
            insert(temp,key);
        }else if(strcmp(inp,"DELETE")==0){
            int key;
            del_freq++;
            scanf("%d",&key);
            Delete(temp,key);
        }else if(strcmp(inp,"SEARCH")==0){
            int key;
            srh_freq++;
            scanf("%d",&key);
            //printf("%d\n",search(temp,key));
            search(temp,key);
        }else if(strcmp(inp,"PRINT")==0){
            print_table(temp);
        }
    }
    printf("%lf\t%lf\t%lf\n",(double) ins/ins_freq,(double) del/del_freq,(double) srh/srh_freq);
}
//////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////hash.c
int getHash(struct HashTable *T, int key)
{
    return ((T->a * key + T->b) % T->countBucket);
}

struct HashTable *init_hash_table(int a, int b, int countBucket)
{
    struct HashTable *table = (struct HashTable *)malloc(sizeof(struct HashTable));
    assert(table != NULL);
    table->a = a;
    table->b = b;
    table->countBucket = countBucket;
    table->buckets = (struct Bucket *)malloc(countBucket * sizeof(struct Bucket));
    assert(table->buckets != NULL);
    return table;
}

struct HashTable *insert(struct HashTable *T, int key)
{
    ins++;
    int bkt = getHash(T, key);
    struct Item *curser = T->buckets[bkt].items;
    bool found = 0;
    while (curser != NULL)
    {
        if (curser->key == key)
        {
            curser->frequency++;
            found = 1;
            break;
        }
        ins++;
        curser = curser->next;
    }
    if (!found)
    {
        struct Item *temp = (struct Item *)malloc(sizeof(struct Item));
        temp->frequency = 1;
        temp->key = key;
        temp->next = T->buckets[bkt].items;
        T->buckets[bkt].items = temp;
    }
    return T;
}

bool search(struct HashTable *T, int key)
{
    srh++;
    int bkt = getHash(T, key);
    struct Item *curser = T->buckets[bkt].items;
    // bool found=0;
    while (curser != NULL)
    {
        if (curser->key == key)
        {
            // curser->frequency++;
            // found=1;
            return true;
        }
        srh++;
        curser = curser->next;
    }
    return false;
}

void print_table(struct HashTable *T)
{
    int bkt = 0;
    while (bkt < T->countBucket)
    {
        struct Item *curser = T->buckets[bkt].items;
        while (curser != NULL)
        {
            printf("%d %d ", curser->key, curser->frequency);
            curser=curser->next;
        }
        printf("\n");
        bkt++;
    }
}

struct HashTable *Delete(struct HashTable *T, int key)
{
    del++;
    int bkt = getHash(T, key);
    if (T->buckets[bkt].items)
    {
        /*if(T->buckets[bkt].items->next==NULL){
            if(T->buckets[bkt].items->key==key){
                free(T->buckets[bkt].items);
                T->buckets[bkt].items=NULL;
            }
        }else{*/
        struct Item *curser = T->buckets[bkt].items;
        if (curser->key == key)
        {
            curser->frequency--;
            if (curser->frequency == 0)
            {
                T->buckets[bkt].items = curser->next;
                free(curser);
            }
        }
        else
        {
            while (curser->next != NULL)
            {
                if (curser->next->key == key)
                {
                    curser->next->frequency--;
                    if (curser->next->frequency == 0)
                    {

                        struct Item *temp = curser->next;
                        curser->next = temp->next;
                        free(temp);
                    }
                    break;
                }
                del++;
                curser = curser->next;
            }
        }
        //}
    }
    return T;
}
/////////////////////////////////////////////////////////////////////////