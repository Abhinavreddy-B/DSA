#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        int n;
        scanf("%d", &n);
        int A[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        Tree my_tree = GenerateTreeFromLevelOrder(n, A);
        printf("%lld\n", findMinNoice(my_tree));
         DestroyTree(my_tree->root);
         free(my_tree);
         my_tree=NULL;
        // printf("%p",my_tree);
        // my_tree=NULL;
    }
}