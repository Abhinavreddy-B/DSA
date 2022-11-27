#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Queue Queue;
typedef struct QueueNode QueueNode;


#define NOELEMENT -1

typedef int ElementType;


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

void QueuePrint(const Queue _s);

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


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    Queue* inp = InitQueue();
    Deque* helper = InitDeque();
    for(int i=0;i<m;i++){
        int temp;
        scanf("%d",&temp);
        while(!DequeIsEmpty(helper)&&DequeBack(helper)>temp){
            PopBack(helper);
        }
        PushBack(helper,temp);
        QueueEnqueue(inp,temp);
    }
    printf("%d ",DequeFront(helper));
    for(int i=0;i<n-m;i++){
        int temp;
        scanf("%d",&temp);
        QueueEnqueue(inp,temp);
        if(DequeFront(helper)==QueueFront(inp)){
            PopFront(helper);
        }
        QueueDequeue(inp);
        while(!DequeIsEmpty(helper)&&DequeBack(helper)>temp){
            PopBack(helper);
        }
        PushBack(helper,temp);
        printf("%d ",DequeFront(helper));
    }
    while(!QueueIsEmpty(inp))
        QueueDequeue(inp);
    free(inp);
    while(!DequeIsEmpty(helper))
        PopFront(helper);
    free(helper);
    printf("\n");
}




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
    if (QueueIsEmpty(_s))
        return NOELEMENT;
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
    if (QueueIsEmpty(_s))
        return NOELEMENT;
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

void QueuePrint(const Queue _s)
{
    QueueNode *iter = _s.bottom;
    while (iter)
    {
        printf("%d ", iter->x);
        iter = iter->up;
    }
    printf("\n");
    return;
}






Deque* InitDeque(){
    Deque* temp = (Deque*) malloc(sizeof(Deque));
    temp->front=NULL;
    temp->back=NULL;
    temp->size=0;
    return temp;
}

ElementType PopFront(Deque* _d){
    if(!_d||DequeIsEmpty(_d))
        return NOELEMENT;
    
    DequeNode* temp=_d->front;
    _d->front=_d->front->next;
    if(_d->front)
        _d->front->prev=NULL;
    else
        _d->back=_d->front;
    ElementType tempele=temp->x;
    free(temp);
    _d->size--;
    return tempele;    
}

ElementType PopBack(Deque* _d){
    if(!_d||DequeIsEmpty(_d))
        return NOELEMENT;
    
    DequeNode* temp=_d->back;
    _d->back=_d->back->prev;
    if(_d->back)
        _d->back->next=NULL;
    else
        _d->front=_d->back;
    ElementType tempele=temp->x;
    free(temp);
    _d->size--;
    return tempele;    
}

void PushFront(Deque* _d,ElementType x){
    DequeNode* temp=(DequeNode*) malloc(sizeof(DequeNode));
    assert(temp!=NULL);
    temp->x=x;
    if(DequeIsEmpty(_d)){
        _d->front=temp;
        _d->back=temp;
        _d->size++;
        return;
    }
    _d->front->prev=temp;
    temp->next=_d->front;
    temp->prev=NULL;
    _d->front=temp;
    _d->size++;
}

void PushBack(Deque* _d,ElementType x){
    DequeNode* temp=(DequeNode*) malloc(sizeof(DequeNode));
    assert(temp!=NULL);
    temp->x=x;
    if(DequeIsEmpty(_d)){
        _d->front=temp;
        _d->back=temp;
        _d->size++;
        return;
    }
    _d->back->next=temp;
    temp->prev=_d->back;
    temp->next=NULL;
    _d->back=temp;
    _d->size++;
}

ElementType DequeFront(const Deque* const _d){
    if(!_d||DequeIsEmpty(_d))
        return NOELEMENT;
    return _d->front->x;
}

ElementType DequeBack(const Deque* const _d){
    if(!_d||DequeIsEmpty(_d))
        return NOELEMENT;
    return _d->back->x;
}

int DequeIsEmpty(const Deque* const _d){
    return (_d->size==0);
}

int DequeSize(const Deque* const _d){
    return _d->size;
}

void DequePrint(const Deque* const _d){
    DequeNode* iter=_d->front;
    while(iter){
        printf("%d ",iter->x);
        iter=iter->next;
    }
}

void DequeReversePrint(const Deque* const _d){
    DequeNode* iter=_d->back;
    while(iter){
        printf("%d ",iter->x);
        iter=iter->prev;
    }
}

