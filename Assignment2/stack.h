#ifndef _STACK_H_
#define _STACK_H_
#include "ElementType.h"
#include <stdio.h>

typedef struct Stack Stack;
typedef struct StackNode StackNode;

struct Stack{
    size_t size;
    StackNode* top;
    StackNode* bottom;
};

struct StackNode{
    ElementType x;
    StackNode* down;
    StackNode* up;
};

Stack* InitStack();
int StackIsEmpty(const Stack* const _s);

ElementType StackPop(Stack* _s);
void StackPush(Stack* _s,ElementType x);

ElementType StackTop(const Stack* const _s);

int StackSize(const Stack* const _s);

void StackPrint(const Stack* const _s);
void StackPrintReverse(const Stack* const _s);

void StackDestroy(Stack* _s);
#endif