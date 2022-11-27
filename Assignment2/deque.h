#ifndef _DEQUE_H_
#define _DEQUE_H_
#include <stdio.h>
#include "ElementType.h"

typedef struct Deque Deque;
typedef struct DequeNode DequeNode;

struct DequeNode{
    ElementType x;
    DequeNode* next;
    DequeNode* prev;
};

struct Deque{
    size_t size;
    DequeNode* front;
    DequeNode* back;
};

Deque* InitDeque();
ElementType PopFront(Deque* _d);
ElementType PopBack(Deque* _d);
void PushFront(Deque* _d,ElementType x);
void PushBack(Deque* _d,ElementType x);
ElementType DequeFront(const Deque* const _d);
ElementType DequeBack(const Deque* const _d);
int DequeIsEmpty(const Deque* const _d);
int DequeSize(const Deque* const _d);
void DequePrint(const Deque* const _d);
void DequeReversePrint(const Deque* const _d);
#endif