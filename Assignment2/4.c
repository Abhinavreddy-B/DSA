//#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
//#include <assert.h>











/********************************************************************************/
//
// function signatures
//

#define NOELEMENT -1

typedef int ElementType;

typedef struct Stack Stack;
typedef struct StackNode StackNode;

struct Stack
{
    size_t size;
    StackNode *top;
    StackNode *bottom;
};

struct StackNode
{
    ElementType x;
    StackNode *down;
    StackNode *up;
};

Stack *InitStack();

int StackIsEmpty(const Stack *const _s);
int StackSize(const Stack *const _s);


ElementType StackPop(Stack *_s);
void StackPush(Stack *_s, ElementType x);
ElementType StackTop(const Stack *const _s);


void StackPrint(const Stack *const _s);
void StackPrintReverse(const Stack *const _s);

void StackDestroy(Stack* _s);

/********************************************************************************/






/*******************************************************************************/
//
// Main code
//

int find_max(int m, int arr[m])
{
    int prev[m];
    int next[m];
    for (int j = 0; j < m; j++)
    {
        prev[j] = 0;
        next[j] = 0;
    }
    Stack *prev_stack = InitStack();
    Stack *next_stack = InitStack();
    for (int j = 0; j < m; j++)
    {
        while (!StackIsEmpty(prev_stack) && arr[StackTop(prev_stack)] >= arr[j])
        {
            StackPop(prev_stack);
        }
        prev[j] = StackIsEmpty(prev_stack) ? -1 : StackTop(prev_stack);
        // if(StackIsEmpty(prev_stack))
        //     prev[j]=-1;
        // else
        //     prev[j]=StackTop(prev_stack);
        StackPush(prev_stack, j);
    }
    for (int j = m - 1; j >= 0; j--)
    {
        while (!StackIsEmpty(next_stack) && arr[StackTop(next_stack)] >= arr[j])
        {
            StackPop(next_stack);
        }
        next[j] = StackIsEmpty(next_stack) ? m : StackTop(next_stack);
        // if(StackIsEmpty(next_stack))
        //     next[j]=m;
        // else
        //     next[j]=StackTop(next_stack);
        StackPush(next_stack, j);
    }
    int max = 0;
    for (int i = 0; i < m; i++)
    {
        if (max < arr[i] * (next[i] - prev[i] - 1))
        {
            max = arr[i] * (next[i] - prev[i] - 1);
        }
    }
    /*while (!StackIsEmpty(prev_stack))
        StackPop(prev_stack);
    free(prev_stack);
    StackDestroy(prev_stack);
    prev_stack=NULL;
    while (!StackIsEmpty(next_stack))
        StackPop(next_stack);
    free(next_stack);
    StackDestroy(next_stack);
    next_stack=NULL;*/
    return max;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[m];
    for (int i = 0; i < m; i++)
        arr[i] = 0;

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        for (int j = 0; j < m; j++)
        {
            char temp;
            scanf("%c", &temp);
            int val = (temp == '.');
            arr[j] = (val != 0) * (arr[j] + 1);
        }
        //int temp2=0;
        int temp2 = find_max(m, arr);
        max = max < temp2 ? temp2 : max;
    }
    printf("%d\n", max);
}

/*************************************************************************************************************/












/************************************************************************************************************/
//
// Stack implementation
//

Stack *InitStack()
{
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->top = NULL;
    temp->bottom = NULL;
    temp->size = 0;
    return temp;
}

int StackIsEmpty(const Stack *const _s)
{
    return (_s->top == NULL);
}

ElementType StackPop(Stack *_s)
{
    if (StackIsEmpty(_s))
        return NOELEMENT;
    StackNode *temp = _s->top;
    _s->top = _s->top->down;
    if (_s->top)
        _s->top->up = NULL;
    else
        _s->bottom = _s->top;
    ElementType tempele = temp->x;
    free(temp);
    _s->size--;
    return tempele;
}

void StackPush(Stack *_s, ElementType x)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    //assert(temp != NULL);
    temp->down = _s->top;
    temp->x = x;
    temp->up = NULL;
    if (StackIsEmpty(_s))
    {
        _s->top = temp;
        _s->bottom = temp;
    }
    else
    {
        _s->top->up = temp;
        _s->top = temp;
    }
    _s->size++;
    return;
}

ElementType StackTop(const Stack *const _s)
{
    if (StackIsEmpty(_s))
        return NOELEMENT;
    return _s->top->x;
}

int StackSize(const Stack *const _s)
{
    return _s->size;
    int count = 0;
    StackNode *iter = _s->top;
    while (iter)
    {
        iter = iter->down;
        count++;
    }
    return count;
}

void StackPrint(const Stack *const _s)
{
    StackNode *iter = _s->top;
    while (iter)
    {
        printf("%d ", iter->x);
        iter = iter->down;
    }
    printf("\n");
    return;
}

void StackPrintReverse(const Stack *const _s)
{
    StackNode *iter = _s->bottom;
    while (iter)
    {
        printf("%d ", iter->x);
        iter = iter->up;
    }
    printf("\n");
    return;
}

void StackDestroy(Stack* _s){
    while(!StackIsEmpty(_s))
        StackPop(_s);
    
    free(_s);
}

/**********************************************************************************************************************/


/*******************************************************************************/
//
// Main code
//

/*int find_max(int m, int arr[m])
{
    int prev[m];
    int next[m];
    for (int j = 0; j < m; j++)
    {
        prev[j] = 0;
        next[j] = 0;
    }
    Stack *prev_stack = InitStack();
    Stack *next_stack = InitStack();
    for (int j = 0; j < m; j++)
    {
        while (!StackIsEmpty(prev_stack) && arr[StackTop(prev_stack)] >= arr[j])
        {
            StackPop(prev_stack);
        }
        prev[j] = StackIsEmpty(prev_stack) ? -1 : StackTop(prev_stack);
        // if(StackIsEmpty(prev_stack))
        //     prev[j]=-1;
        // else
        //     prev[j]=StackTop(prev_stack);
        StackPush(prev_stack, j);
    }
    for (int j = m - 1; j >= 0; j--)
    {
        while (!StackIsEmpty(next_stack) && arr[StackTop(next_stack)] >= arr[j])
        {
            StackPop(next_stack);
        }
        next[j] = StackIsEmpty(next_stack) ? m : StackTop(next_stack);
        // if(StackIsEmpty(next_stack))
        //     next[j]=m;
        // else
        //     next[j]=StackTop(next_stack);
        StackPush(next_stack, j);
    }
    int max = 0;
    for (int i = 0; i < m; i++)
    {
        if (max < arr[i] * (next[i] - prev[i] - 1))
        {
            max = arr[i] * (next[i] - prev[i] - 1);
        }
    }
    while (!StackIsEmpty(prev_stack))
        StackPop(prev_stack);
    free(prev_stack);
    StackDestroy(prev_stack);
    prev_stack=NULL;
    while (!StackIsEmpty(next_stack))
        StackPop(next_stack);
    free(next_stack);
    StackDestroy(next_stack);
    next_stack=NULL;
    return max;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[m];
    for (int i = 0; i < m; i++)
        arr[i] = 0;

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        for (int j = 0; j < m; j++)
        {
            char temp;
            scanf("%c", &temp);
            int val = (temp == '.');
            arr[j] = (val != 0) * (arr[j] + 1);
        }
        int temp2 = find_max(m, arr);
        max = max < temp2 ? temp2 : max;
    }
    printf("%d\n", max);
}
*/
/*************************************************************************************************************/
