#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "heaps.h"

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
            qsort(arr[i],k,sizeof(arr[i][0]),INT_CMP);
        }
        Heaps* h=_Init_Heap(1000010,HeapCmp);
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
            insertIntoHeap(h,tempinit);
            flag[0][0]=i;
            //int flag2=1;
            int temparr[k];
            for(int count = 0; count<k;count++){
                HeapElement temp=removeMinFromHeap(h);
                temparr[count]=temp.sum;
                if(temp.a<k-1&&flag[temp.a+1][temp.b]<i){
                    HeapElement temp3=temp;
                    temp3.a++;
                    temp3.sum+=Arrprev[temp3.a]-Arrprev[temp3.a-1];
                    insertIntoHeap(h,temp3);
                    flag[temp.a+1][temp.b]=i;
                }
                if(temp.b<k-1&&flag[temp.a][temp.b+1]<i){
                    HeapElement temp3=temp;
                    temp3.b++;
                    temp3.sum+=arr[i][temp3.b]-arr[i][temp3.b-1];
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
    }
}