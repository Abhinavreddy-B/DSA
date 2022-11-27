#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct mystruct
{
    char _c;
    int left;
    int right;
    int pospreorder;
    int index;
    int parent;
} MyStruct;

void Helper(int pos, int *preorderpos, MyStruct *input, char *Preoprderarray)
{
    if (pos == -1)
    {
        return;
    }
    Preoprderarray[*preorderpos] = input[pos]._c;
    input[pos].pospreorder = *preorderpos;
    (*preorderpos)++;
    Helper(input[pos].left, preorderpos, input, Preoprderarray);
    Helper(input[pos].right, preorderpos, input, Preoprderarray);
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("\n");
    MyStruct *Arr = (MyStruct *)malloc(n * sizeof(MyStruct));
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &Arr[i]._c);
        Arr[i].parent = -1;
        Arr[i].left = -1;
        Arr[i].right = -1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int node, child, dir;
        scanf("%d%d%d", &node, &child, &dir);
        if (dir == 1)
        {
            Arr[node - 1].left = child - 1;
            Arr[child - 1].parent = node - 1;
        }
        else
        {
            Arr[node - 1].right = child - 1;
            Arr[child - 1].parent = node - 1;
        }
    }
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (Arr[i].parent == -1)
        {
            root = i;
            break;
        }
    }
    char preorderarray[n+1];
    preorderarray[n]='\0';
    int preorderpos = 0;
    Helper(root, &preorderpos, Arr, preorderarray);
    char S[1000100];
    scanf("%s", S);
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int mode;
        scanf("%d", &mode);
        if(mode==1){
            int position;
            char _c;
            scanf("%d",&position);
            position--;
            scanf(" %c",&_c);
            Arr[position]._c=_c;
            preorderarray[ Arr[position].pospreorder ]=_c;
        }else{
            int pos,left,right;
            scanf("%d%d%d",&left,&right,&pos);
            pos--;
            left--;
            right--;
            if(strncmp(preorderarray+Arr[pos].pospreorder,S+left,right-left+1)==0){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
}