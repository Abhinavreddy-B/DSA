#include <stdio.h>
typedef long long ll;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int Arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (Arr[i] <= k)
        {
            continue;
        }
        int check = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (Arr[i] > Arr[i + 1])
            {
                check = 0;
                break;
            }
        }
        if (check)
        {
            printf("%d\n",count);
            return 0;
        }
        // swapping elements
        int temp = k;
        k = Arr[i];
        Arr[i] = temp;
        // k=Arr[i]-k+(Arr[i]=k);
        count++;
    }
    int flag = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (Arr[i] > Arr[i + 1])
        {
            flag = 0;
            break;
        }
    }
    if (!flag)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", count);
    }
}