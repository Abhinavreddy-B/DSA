#ifndef _TREE_H_
#define _TREE_H_
#include "treenode.h"
typedef long long ll;

typedef struct tree* Tree;

//hold the pointer to root node
struct tree{
    TreeNode root;
};

//used internally in find minimum noice lite tree
typedef struct returnstruct{
    ll min;
    ll max;
    ll sum;

    ////is used as a mode to check if the subtree is 
    //ascending - islite=1
    //descending - islite=-1
    //leafnode - islite=2
    //NULL node - islite=2
    //none of the above - islite=0
    int islite;
}ReturnStruct;

Tree InitTree(void);
int IsTreeEmpty(Tree _t);
Tree GenerateTreeFromLevelOrder(int n,int A[]);

//function provided to user
ll findMinNoice(Tree _t);

//function abstracted from user , used internally
ReturnStruct findminrecursive(TreeNode _tn,ll* a);
void DestroyTree(TreeNode _t);

#endif