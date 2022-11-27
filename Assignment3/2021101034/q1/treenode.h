#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

typedef long long ll;
typedef struct treenode *TreeNode;

struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;
    // ll min;
    // ll max;
    // ll sum;
    // ll currsum;
    int children;
    // int islite;
};

TreeNode InitTreeNode(int _x);
#endif