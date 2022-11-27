#ifndef _HASH_HEADER_
#define _HASH_HEADER_
#include <stdbool.h>

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
#endif