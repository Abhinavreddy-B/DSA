#ifndef _HEAPS_HEADER_
#define _HEAPS_HEADER_
#include <stdio.h>

typedef long long ll;
typedef ll ElementType;

typedef struct heaps{
    size_t curr_size;
    size_t max_size;
    ElementType* Arr;   
    int (*comparator_funct)(ElementType a,ElementType b);
} Heaps;

Heaps* _Init_Heap(size_t Max_size,int (*cmp)(ElementType a,ElementType b));
void insertIntoHeap(Heaps* _h,ElementType _t);
ElementType GetMinHeap(Heaps* _h);
Heaps* buildHeap(size_t _n,ElementType arr[],int (*cmp)(ElementType a, ElementType b));
ElementType removeMinFromHeap(Heaps* _h);
size_t HeapSize(Heaps* _h);

#endif