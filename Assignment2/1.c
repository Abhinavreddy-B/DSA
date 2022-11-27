#include <stdio.h>
//#include "stack.h"
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define NOELEMENT -1

typedef long long ElementType;

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

typedef long long ll;

ll gcd(ll x, ll y)
{
    /*if(x==0)
        return y;
    if(y==0)
        return x;

    int min=(x>y?y:x);
    while(min){
        if(x%min==0&&y%min==0)
            return min;
        min--;
    }*/
    return (x==0?y:gcd((y+x)%x,x));
}


/*int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}*/

// Function to return LCM of two numbers
ll lcm(ll a, ll b)
{
    return (a/gcd(a,b))*b;
}

int main()
{
    int n;
    scanf("%d", &n);
    Stack *st = InitStack();
    while (n--)
    {
        ll temp;
        scanf("%lld", &temp);
        /*if(gcd(StackTop(st),temp)<=1){
            StackPush(st,temp);
            continue;
        }*/
        StackPush(st, temp);
        while (StackSize(st)>=2)
        {
            ll t = StackPop(st);
            ll t2 = StackTop(st);
            ll temp=gcd(t, t2);
            if (temp > 1)
            {
                StackPop(st);
                StackPush(st, ((t/temp)*t2));
            }
            else
            {
                StackPush(st,t);
                break;
            }
        }
        //StackPush(st, temp);
    }
    printf("%d\n", StackSize(st));
    //StackPrintReverse(st);
    Stack* st2=InitStack();
    while(!StackIsEmpty(st)){
        StackPush(st2,StackPop(st));
    }
    StackPrint(st2);
    /*while(!StackIsEmpty(st))
        StackPop(st);
    free(st);*/
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
    /*int count=0;
    StackNode* iter=_s->top;
    while(iter){
        iter=iter->down;
        count++;
    }
    return count;*/
}

void StackPrint(const Stack* const _s){
    StackNode* iter = _s->top;
    while(iter){
        printf("%lld ",iter->x);
        iter=iter->down;
    }
    printf("\n");
    return;
}

void StackPrintReverse(const Stack* const _s){
    StackNode* iter=_s->bottom;
    while(iter){
        printf("%lld ",iter->x);
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