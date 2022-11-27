#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heaps.h"

void perculateDown(Heaps *h, int pos);

Heaps* _Init_Heap(size_t Max_size,int (*cmp)(ElementType a,ElementType b))
{
    Heaps *temp = (Heaps *)malloc(sizeof(Heaps));
    assert(temp != NULL);
    temp->max_size = Max_size;
    temp->comparator_funct = cmp;
    temp->curr_size = 0;
    temp->Arr = (ElementType *)malloc((Max_size + 1) * sizeof(ElementType));
    assert(temp->Arr!=NULL);
    return temp;
}

void insertIntoHeap(Heaps *h, ElementType _t)
{
    h->Arr[++h->curr_size] = _t;
    int iter = h->curr_size;
    while (iter > 1 && (*(h->comparator_funct))(h->Arr[iter], h->Arr[iter / 2]))
    {
        h->Arr[iter] = h->Arr[iter] + h->Arr[iter / 2] - (h->Arr[iter / 2] = h->Arr[iter]);
        iter /= 2;
    }
}

ElementType GetMinHeap(Heaps *h)
{
    return h->Arr[1];
}

Heaps* buildHeap(size_t _n,ElementType arr[],int (*cmp)(ElementType a, ElementType b))
{
    Heaps* h=_Init_Heap(_n,cmp);
    for(int i=0;i<_n;i++){
        h->Arr[i+1]=arr[i];
    }
    h->curr_size=_n;
    for(int i=_n/2;i>0;i--){
        perculateDown(h,i);
    }
    return h;
}

ElementType removeMinFromHeap(Heaps* h){
    ElementType temp=h->Arr[1];
    h->Arr[1]=h->Arr[h->curr_size];
    h->curr_size--;
    perculateDown(h,1);
    return temp;
}

void perculateDown(Heaps *h, int pos)
{
    int iter = pos;
    while (iter < h->curr_size)
    {
        if(2*iter>h->curr_size){
            return;
        }else
        if (2 * iter + 1 > h->curr_size)
        {
            if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[iter]))
            {
                h->Arr[iter] = h->Arr[iter] + h->Arr[2 * iter] - (h->Arr[2 * iter] = h->Arr[iter]);
                
            }
            return;
        }
        else
        {
            if ((*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter]) && (*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter + 1]))
            {
                return;
            }
            else if ((*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter]) && (*(h->comparator_funct))(h->Arr[2 * iter + 1], h->Arr[iter]))
            {
                h->Arr[iter] = h->Arr[iter] + h->Arr[2 * iter + 1] - (h->Arr[2 * iter + 1] = h->Arr[iter]);
                iter = 2 * iter + 1;
            }
            else if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[iter]) && (*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter + 1]))
            {
                h->Arr[iter] = h->Arr[iter] + h->Arr[2 * iter] - (h->Arr[2 * iter] = h->Arr[iter]);
                iter=2*iter;
            }
            else
            {
                if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[2 * iter + 1]))
                {

                    h->Arr[iter] = h->Arr[iter] + h->Arr[2 * iter] - (h->Arr[2 * iter] = h->Arr[iter]);
                    iter=2*iter;
                }
                else
                {
                    h->Arr[iter] = h->Arr[iter] + h->Arr[2 * iter + 1] - (h->Arr[2 * iter + 1] = h->Arr[iter]);
                    iter=2*iter+1;
                }
            }
        }
    }
}

size_t HeapSize(Heaps* _h){
    return _h->curr_size;
}