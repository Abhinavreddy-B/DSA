#include <stdio.h>
#include <stdlib.h>
typedef long long ll;


//structure to hold the element and its frequency
struct frequency
{
    int num;
    int freq;
};

//comparator function for integer element
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

//comparator function for arranging in increasing order of frequency
int cmpst2(const void *a, const void *b)
{
    struct frequency temp = *(struct frequency *)a;
    struct frequency temp2 = *(struct frequency *)b;
    return temp.freq - temp2.freq;
}


int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int Arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &Arr[i]);
        }

        //sorting array in increasing order of values
        qsort(Arr, n, sizeof(int), cmp);

        //count the number of distinct elements
        int count = 1;

        
        //count the number of distinct elements
        for (int i = 0; i < n - 1; i++)
        {
            count += (Arr[i] != Arr[i + 1]);
        }


        struct frequency f[count];
        for (int i = 0; i < count; i++)
        {
            //setting initial frequency to 1 (not incrementing for the first distinct element in the below loop)
            f[i].freq = 1;
        }

        //temporary variable
        int pos = 0;
        for (int i = 0; i < count; i++)
        {
            f[i].num = Arr[pos];
            while (pos != n - 1 && Arr[pos] == Arr[pos + 1])
            {
                pos++;
                f[i].freq++;
            }
            pos++;
        }

        //sorting the frequency array in increasing order of frequency
        qsort(f, count, sizeof(f[0]), cmpst2);

        //finding maxumum frequency
        int max_freq = f[count - 1].freq;

        //fincding no of elements with maximum freq
        int no_of_max_freq = 1;
        for (int i = count - 1; i > 0 && f[i - 1].freq == f[i].freq; i--)
        {
            no_of_max_freq++;
        }


        // printf("%d\n%d\n",max_freq,no_of_max_freq);

        //special case
        if (max_freq == 1)
        {
            printf("%d\n", n);
        }
        else
        {
            printf("%d\n", (n - no_of_max_freq) / (max_freq - 1) - 1);
        }
    }
}