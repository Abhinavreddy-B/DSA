#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash.h"

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
                curser = curser->next;
            }
        }
        //}
    }
    return T;
}