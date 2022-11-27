#include "deque.h"
#include <stdlib.h>
#include <assert.h>


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