#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "ElementType.h"
#include <stdio.h>

typedef struct Queue Queue;
typedef struct QueueNode QueueNode;

struct Queue{
    size_t size;
    QueueNode* top;
    QueueNode* bottom;
};

struct QueueNode{
    ElementType x;
    QueueNode* down;
    QueueNode* up;
};

Queue* InitQueue();

int QueueIsEmpty(const Queue* const _s);

ElementType QueueDequeue(Queue* _s);
void QueueEnqueue(Queue* _s,ElementType x);

ElementType QueueFront(const Queue* const _s);

int QueueSize(const Queue* const _s);

//void QueuePrint(const Queue _s);
#endif