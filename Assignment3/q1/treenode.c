#include "treenode.h"
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

TreeNode InitTreeNode(int _x){
    TreeNode temp=(TreeNode) malloc(sizeof(struct treenode));
    assert(temp!=NULL);
    temp->left=NULL;
    temp->right=NULL;
    temp->value=_x;
    /*temp->sum=0;
    temp->min=INT_MAX;
    temp->max=INT_MIN;
    temp->currsum=0;*/
    temp->children=0;
    return temp;
}