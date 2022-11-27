#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef long long ll;
typedef struct _my_st_{
    ll sumTillNow;
    int original_index;
}Myst;

typedef Myst ElementType;

typedef struct heaps{
    size_t curr_size;
    size_t max_size;
    ElementType* Arr;   
    int (*comparator_funct)(ElementType a,ElementType b);
} Heaps;

Heaps* _Init_Heap(size_t Max_size,int (*cmp)(ElementType a,ElementType b));
void insertIntoHeap(Heaps* _h,ElementType _t);
ElementType GetMinHeap(Heaps* _h);
Heaps* buildHeap(size_t _n,ElementType arr[],int (*cmp)(ElementType a, ElementType b));
ElementType removeMinFromHeap(Heaps* _h);


int cmp(ElementType a, ElementType b)
{
    if (a.sumTillNow < b.sumTillNow)
    {
        return 1;
    }
    else if (a.sumTillNow == b.sumTillNow && a.original_index < b.original_index)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    ll inp[n];
    ElementType Pref[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &inp[i]);
        Pref[i].sumTillNow=inp[i];
        Pref[i].original_index=i;
        if (i > 0)
        {
            Pref[i].sumTillNow += Pref[i - 1].sumTillNow;
        }
        
    }
    Heaps* h=buildHeap(n-1,Pref,cmp);
    int state[n];
    for(int i=0;i<n;i++){
        state[i]=0;
    }
    for(int i=0;i<k-1;i++){
        state[removeMinFromHeap(h).original_index]=1;
    }
    ll ans=0;
    ll count=1;
    for(int i=0;i<n;i++){
        ans+=inp[i]*count;
        if(state[i]==1){
            count++;
        }
    }
    printf("%lld\n",ans);
}

void perculateDown(Heaps *h, int pos);

Heaps *_Init_Heap(size_t Max_size, int (*cmp)(ElementType a, ElementType b))
{
    Heaps *temp = (Heaps *)malloc(sizeof(Heaps));
    assert(temp != NULL);
    temp->max_size = Max_size;
    temp->comparator_funct = cmp;
    temp->curr_size = 0;
    temp->Arr = (ElementType *)malloc((Max_size + 1) * sizeof(ElementType));
    return temp;
}

void insertIntoHeap(Heaps *h, ElementType _t)
{
    h->Arr[++h->curr_size] = _t;
    int iter = h->curr_size;
    while (iter > 1 && (*(h->comparator_funct))(h->Arr[iter], h->Arr[iter / 2]))
    {
        ElementType temp = h->Arr[iter];
        h->Arr[iter] = h->Arr[iter / 2];
        h->Arr[iter / 2] = temp;
        iter /= 2;
    }
}

ElementType GetMinHeap(Heaps *h)
{
    return h->Arr[1];
}

Heaps *buildHeap(size_t _n, ElementType arr[], int (*cmp)(ElementType a, ElementType b))
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

ElementType removeMinFromHeap(Heaps *h)
{
    ElementType temp = h->Arr[1];
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
                ElementType temp = h->Arr[iter];
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
                ElementType temp = h->Arr[iter];
                h->Arr[iter] = h->Arr[2 * iter + 1];
                h->Arr[2 * iter + 1] = temp;
                iter = 2 * iter + 1;
            }
            else if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[iter]) && (*(h->comparator_funct))(h->Arr[iter], h->Arr[2 * iter + 1]))
            {
                ElementType temp = h->Arr[iter];
                h->Arr[iter] = h->Arr[2 * iter];
                h->Arr[2 * iter] = temp;
                iter = 2 * iter;
            }
            else
            {
                if ((*(h->comparator_funct))(h->Arr[2 * iter], h->Arr[2 * iter + 1]))
                {

                    ElementType temp = h->Arr[iter];
                    h->Arr[iter] = h->Arr[2 * iter];
                    h->Arr[2 * iter] = temp;
                    iter = 2 * iter;
                }
                else
                {
                    ElementType temp = h->Arr[iter];
                    h->Arr[iter] = h->Arr[2 * iter + 1];
                    h->Arr[2 * iter + 1] = temp;
                    iter = 2 * iter + 1;
                }
            }
        }
    }
}