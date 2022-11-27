#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NOELEMENT -1

typedef int ElementType;

typedef long long ll;


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


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    ll sum=0;
    Stack* right=InitStack();
    for(int i=0;i<n;i++){
        while(!StackIsEmpty(right)&&arr[StackTop(right)]<arr[i]){
            sum+=i-StackTop(right)+1;
            StackPop(right);
        }
        StackPush(right,i);
    }
    while(!StackIsEmpty(right))
        StackPop(right);
    for(int i=n-1;i>=0;i--){
        while(!StackIsEmpty(right)&&arr[StackTop(right)]<arr[i]){
            sum+=StackTop(right)-i+1;
            StackPop(right);
        }
        StackPush(right,i);
    }
    /*while(!StackIsEmpty(right))
        StackPop(right);
    free(right);*/
    printf("%lld\n",sum);
}

Stack* InitStack(){
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp->top=NULL;
    temp->bottom=NULL;
    temp->size=0;
    return temp;
}

int StackIsEmpty(const Stack* const _s){
    return (_s->top==NULL);
}

ElementType StackPop(Stack* _s){
    if(StackIsEmpty(_s))
        return NOELEMENT;
    StackNode* temp=_s->top;
    _s->top=_s->top->down;
    if(_s->top)
        _s->top->up=NULL;
    else
        _s->bottom=_s->top;
    ElementType tempele=temp->x;
    free(temp);
    _s->size--;
    return tempele;
}

void StackPush(Stack* _s,ElementType x){
    StackNode* temp=(StackNode *) malloc(sizeof(StackNode));
    assert(temp!=NULL);
    temp->down=_s->top;
    temp->x=x;
    temp->up=NULL;
    if(StackIsEmpty(_s)){
        _s->top=temp;
        _s->bottom=temp;
    }else{
        _s->top->up=temp;
        _s->top=temp;
    }
    _s->size++;
    return;
}

ElementType StackTop(const Stack* const _s){
    if(StackIsEmpty(_s))
        return NOELEMENT;
    return _s->top->x;
}

int StackSize(const Stack* const _s){
    return _s->size;
    int count=0;
    StackNode* iter=_s->top;
    while(iter){
        iter=iter->down;
        count++;
    }
    return count;
}

void StackPrint(const Stack* const _s){
    StackNode* iter = _s->top;
    while(iter){
        printf("%d ",iter->x);
        iter=iter->down;
    }
    printf("\n");
    return;
}

void StackPrintReverse(const Stack* const _s){
    StackNode* iter=_s->bottom;
    while(iter){
        printf("%d ",iter->x);
        iter=iter->up;
    }
    printf("\n");
    return;
}


void StackDestroy(Stack* _s){
    while(!StackIsEmpty(_s))
        StackPop(_s);
    
    free(_s);
}