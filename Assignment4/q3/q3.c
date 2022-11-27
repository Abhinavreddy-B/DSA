#include <stdio.h>
#include "heaps.h"
#include "ElementType.h"

typedef long long ll;

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