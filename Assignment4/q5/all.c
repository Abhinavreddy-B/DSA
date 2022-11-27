#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

typedef long long ll;
typedef struct _HEAP_STRUCT_{
    ll sum;
    int a;
    int b;
} HeapElement;

typedef struct heaps
{
    size_t curr_size;
    size_t max_size;
    HeapElement *Arr;
    int (*comparator_funct)(HeapElement a, HeapElement b);
} Heaps;

Heaps *_Init_Heap(size_t Max_size, int (*cmp)(HeapElement a, HeapElement b));
void insertIntoHeap(Heaps *_h, HeapElement _t);
HeapElement GetMinHeap(Heaps *_h);
Heaps *buildHeap(size_t _n, HeapElement arr[], int (*cmp)(HeapElement a, HeapElement b));
HeapElement removeMinFromHeap(Heaps *_h);

typedef long long ll;

int INT_CMP(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int HeapCmp(HeapElement a, HeapElement b)
{
    if (a.sum < b.sum)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int k;
        scanf("%d", &k);
        int arr[k][k];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                scanf("%d",&arr[i][j]);
            }
            qsort(arr[i],k,sizeof(int),INT_CMP);
        }
        Heaps* h=_Init_Heap(1000000,HeapCmp);
        int Arrprev[k];
        for(int i=0;i<k;i++){
            Arrprev[i]=arr[0][i];
        }
        int flag[k][k];
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                flag[i][j]=0;
            }
        }
        for(int i=1;i<k;i++){
            HeapElement tempinit={Arrprev[0]+arr[i][0],0,0};
            //assert(h->curr_size<=h->max_size);
            insertIntoHeap(h,tempinit);
            flag[0][0]=i;
            //int flag2=1;
            int temparr[k];
            for(int count = 0; count<k;count++){
                assert(h->curr_size>0);
                HeapElement temp=removeMinFromHeap(h);
                temparr[count]=temp.sum;
                if(temp.a<k-1&&flag[temp.a+1][temp.b]<i){
                    HeapElement temp3=temp;
                    temp3.a++;
                    temp3.sum+=Arrprev[temp3.a]-Arrprev[temp3.a-1];
                    assert(h->curr_size<=h->max_size);
                    insertIntoHeap(h,temp3);
                    flag[temp.a+1][temp.b]=i;
                }
                if(temp.b<k-1&&flag[temp.a][temp.b+1]<i){
                    HeapElement temp3=temp;
                    temp3.b++;
                    temp3.sum+=arr[i][temp3.b]-arr[i][temp3.b-1];
                    assert(h->curr_size<=h->max_size);
                    insertIntoHeap(h,temp3);
                    flag[temp.a][temp.b+1]=i;
                }
            }
            for(int i=0;i<k;i++){
                Arrprev[i]=temparr[i];
            }
            h->curr_size=0;
        }
        for(int i=0;i<k;i++){
            printf("%d ",Arrprev[i]);
        }
        printf("\n");
        free(h->Arr);
        free(h);
    }
}

void perculateDown(Heaps *h, int pos);

Heaps *_Init_Heap(size_t Max_size, int (*cmp)(HeapElement a, HeapElement b))
{
    Heaps *temp = (Heaps *)malloc(sizeof(Heaps));
    assert(temp != NULL);
    temp->max_size = Max_size;
    temp->comparator_funct = cmp;
    temp->curr_size = 0;
    temp->Arr = (HeapElement *)malloc((Max_size + 1) * sizeof(HeapElement));
    return temp;
}

void insertIntoHeap(Heaps *h, HeapElement _t)
{
    h->Arr[h->curr_size+1] = _t;
    int iter = h->curr_size+1;
    while (iter > 1 && (*(h->comparator_funct))(h->Arr[iter], h->Arr[iter / 2]))
    {
        HeapElement temp = h->Arr[iter];
        h->Arr[iter] = h->Arr[iter / 2];
        h->Arr[iter / 2] = temp;
        iter /= 2;
    }
    h->curr_size++;
}

HeapElement GetMinHeap(Heaps *h)
{
    return h->Arr[1];
}

Heaps *buildHeap(size_t _n, HeapElement arr[], int (*cmp)(HeapElement a, HeapElement b))
{
    Heaps *h = _Init_Heap(_n, cmp);
    for (int i = 0; i < _n; i++)
    {
        h->Arr[i + 1] = arr[i];
    }
    h->curr_size = _n;
    for (int i = _n / 2; i > 0; i--)
    {
        perculateDown(h, i);
    }
    return h;
}

HeapElement removeMinFromHeap(Heaps *h)
{
    
        assert(h->curr_size>=1);
    
    HeapElement temp = h->Arr[1];
    h->Arr[1] = h->Arr[h->curr_size];
    h->curr_size--;
    perculateDown(h, 1);
    return temp;
}

void perculateDown(Heaps *h, int pos)
{
    int iter = pos;
    while (iter < h->curr_size)
    {
        if (2 * iter > h->curr_size)
        {
            return;
        }
        else if (2 * iter + 1 > h->curr_size)
        {
            if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[iter]))
            {
                HeapElement temp = h->Arr[iter];
                h->Arr[iter] = h->Arr[2 * iter];
                h->Arr[2 * iter] = temp;
            }
            return;
        }
        else
        {
            if ((*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter]) && (*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter + 1]))
            {
                return;
            }
            else if ((*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter]) && (*(h->comparator_funct))(h->Arr[2 * iter + 1], h->Arr[iter]))
            {
                HeapElement temp = h->Arr[iter];
                h->Arr[iter] = h->Arr[2 * iter + 1];
                h->Arr[2 * iter + 1] = temp;
                iter = 2 * iter + 1;
            }
            else if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[iter]) && (*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter + 1]))
            {
                HeapElement temp = h->Arr[iter];
                h->Arr[iter] = h->Arr[2 * iter];
                h->Arr[2 * iter] = temp;
                iter = 2 * iter;
            }
            else
            {
                if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[2 * iter + 1]))
                {

                    HeapElement temp = h->Arr[iter];
                    h->Arr[iter] = h->Arr[2 * iter];
                    h->Arr[2 * iter] = temp;
                    iter = 2 * iter;
                }
                else
                {
                    HeapElement temp = h->Arr[iter];
                    h->Arr[iter] = h->Arr[2 * iter + 1];
                    h->Arr[2 * iter + 1] = temp;
                    iter = 2 * iter + 1;
                }
            }
        }
    }
}
