#include "deque.h"
#include <stdio.h>

int main(){
    Dequeue* my_deque=InitDequeue();
    PushBack(my_deque,1);
    //DequeuePrint(my_deque);
    PushFront(my_deque,2);
    PushBack(my_deque,3);
    DequeuePrint(my_deque);
    
    printf("\n%d\n",DequeueBack(my_deque));
    PopBack(my_deque);
    printf("\n%d\n",DequeueBack(my_deque));
    PopBack(my_deque);
    printf("\n%d\n",DequeueBack(my_deque));
    PopBack(my_deque);
    DequeuePrint(my_deque);
    printf("\n%d\n",DequeueBack(my_deque));
}