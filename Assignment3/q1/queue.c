#include "ElementType.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Queue* InitQueue(){
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    temp->top=NULL;
    temp->bottom=NULL;
    temp->size=0;
    return temp;
}

int QueueIsEmpty(const Queue* const _s)
{
    return (_s->top == NULL);
}

ElementType QueueDequeue(Queue *_s)
{
    /*if (QueueIsEmpty(_s))
        return NOELEMENT;*/
    QueueNode *temp = _s->bottom;
    _s->bottom = _s->bottom->up;
    if (_s->bottom)
        _s->bottom->down = NULL;
    else
        _s->top=_s->bottom;
    ElementType tempele = temp->x;
    free(temp);
    _s->size--;
    return tempele;
}

void QueueEnqueue(Queue *_s, ElementType x)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    assert(temp != NULL);
    temp->down = _s->top;
    temp->x = x;
    temp->up = NULL;
    if (QueueIsEmpty(_s)){
        _s->top = temp;
        _s->bottom=temp;
    }else{
        _s->top->up = temp;
        _s->top = temp;
    }
    _s->size++;
    return;
}

ElementType QueueFront(const Queue *const _s)
{
    /*if (QueueIsEmpty(_s))
        return NOELEMENT;*/
    return _s->bottom->x;
}

int QueueSize(const Queue *const _s)
{
    return _s->size;
    int count = 0;
    QueueNode *iter = _s->top;
    while (iter)
    {
        iter = iter->down;
        count++;
    }
    return count;
}

/*void QueuePrint(const Queue _s)
{
    QueueNode *iter = _s.bottom;
    while (iter)
    {
        printf("%d ", iter->x);
        iter = iter->up;
    }
    printf("\n");
    return;
}*/