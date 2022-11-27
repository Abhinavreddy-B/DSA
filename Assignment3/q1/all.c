#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

/////////////////////////////////////////////////////////////////treenode.h
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
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////Elementtype.h
typedef TreeNode ElementType;
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////Queue.h
typedef struct Queue Queue;
typedef struct QueueNode QueueNode;

struct Queue
{
    size_t size;
    QueueNode *top;
    QueueNode *bottom;
};

struct QueueNode
{
    ElementType x;
    QueueNode *down;
    QueueNode *up;
};

Queue *InitQueue();

int QueueIsEmpty(const Queue *const _s);

ElementType QueueDequeue(Queue *_s);
void QueueEnqueue(Queue *_s, ElementType x);

ElementType QueueFront(const Queue *const _s);

int QueueSize(const Queue *const _s);
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////tree.h
typedef struct tree *Tree;

// hold the pointer to root node
struct tree
{
    TreeNode root;
};

// used internally in find minimum noice lite tree
typedef struct returnstruct
{
    ll min;
    ll max;
    ll sum;

    ////is used as a mode to check if the subtree is
    // ascending - islite=1
    // descending - islite=-1
    // leafnode - islite=2
    // NULL node - islite=2
    // none of the above - islite=0
    int islite;
} ReturnStruct;

Tree InitTree(void);
int IsTreeEmpty(Tree _t);
Tree GenerateTreeFromLevelOrder(int n, int A[]);

// function provided to user
ll findMinNoice(Tree _t);

// function abstracted from user , used internally
ReturnStruct findminrecursive(TreeNode _tn, ll *a);
void DestroyTree(TreeNode _t);
///////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////main code
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
        // printf("%p",my_tree);
        // my_tree=NULL;
    }
}
///////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////treenode.c

TreeNode InitTreeNode(int _x)
{
    TreeNode temp = (TreeNode)malloc(sizeof(struct treenode));
    assert(temp != NULL);
    temp->left = NULL;
    temp->right = NULL;
    temp->value = _x;
    /*temp->sum=0;
    temp->min=INT_MAX;
    temp->max=INT_MIN;
    temp->currsum=0;*/
    temp->children = 0;
    return temp;
}
/////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////tree.c

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

Tree InitTree(void)
{
    Tree temp = (Tree)malloc(sizeof(struct tree));
    assert(temp != NULL);
    temp->root = NULL;
    return temp;
}

int IsTreeEmpty(Tree _t)
{
    return (_t->root == NULL);
}

Tree GenerateTreeFromLevelOrder(int n, int A[])
{
    // generating a queue
    Queue *order = InitQueue();

    // generating a binary tree
    Tree BinaryTree = InitTree();

    // for root node
    TreeNode tempnode = InitTreeNode(A[0]);
    QueueEnqueue(order, tempnode);
    BinaryTree->root = tempnode;
    int pos = 1;
    while (pos < n)
    {
        TreeNode tempnode = InitTreeNode(A[pos]);

        // if the child is not null
        if (A[pos] != 0)
            QueueEnqueue(order, tempnode);

        // if i am inserting the first child (including NULL child also)
        if (QueueFront(order)->children == 0)
        {
            // if child is not NULL
            if (tempnode->value != 0)
                QueueFront(order)->left = tempnode;

            // used internally to could how many children are inserted (including NULL child)
            QueueFront(order)->children++;
        }

        // if i am inserting the second child ( including NULL children)
        else if (QueueFront(order)->children == 1)
        {
            // if child not NULL
            if (tempnode->value != 0)
                QueueFront(order)->right = tempnode;

            // used internally to could how many children are inserted (including NULL child)
            QueueFront(order)->children++;

            // removing from the Queue
            QueueDequeue(order);
        }
        if(tempnode->value == 0){
            free(tempnode);
        }
        pos++;
    }

    ////destriying the Queue
    while (!QueueIsEmpty(order))
        QueueDequeue(order);
    free(order);
    /////

    // return the created Tree
    return BinaryTree;
}

ll findMinNoice(Tree _t)
{
    // initialise answer with INT_MAX
    ll ans = INT_MAX;
    /*ReturnStruct temp;
    temp.islite = 0;
    temp.max = INT_MIN;
    temp.min = INT_MAX;
    temp.sum = 0;*/

    // recursive function to solve for the minimum possible answer
    findminrecursive(_t->root, &ans);
    return ans;
}

ReturnStruct findminrecursive(TreeNode _tn, ll *a)
{
    // structure to hold different things such as minimum,maximum,sum
    ReturnStruct temp;
    temp.islite = 0;
    temp.max = INT_MIN;
    temp.min = INT_MAX;
    temp.sum = 0;

    // base case
    if (_tn == NULL)
    {
        temp.islite = 2;
        return temp;
    }

    temp.max = _tn->value;
    temp.min = _tn->value;

    ReturnStruct left = findminrecursive(_tn->left, a);
    ReturnStruct right = findminrecursive(_tn->right, a);

    // when the childer itself are not lite trees / one of them is ascending and the other descending
    if (left.islite == 0 || right.islite == 0 || left.islite * right.islite == -1)
    {
        return temp;
    }
    /*if (left.islite * right.islite == -1)
        return temp;*/

    /*if ((_tn->value>left.max&&_tn->value>right.min)||(_tn->value<left.min&&_tn->value>right.max))
        return temp;*/

    // leaf Node
    if (_tn->left == NULL && _tn->right == NULL)
    {
        temp.max = _tn->value;
        temp.min = _tn->value;
        temp.islite = 2;
    }
    // incase of ascending lite tree
    else if (left.max < _tn->value && _tn->value < right.min && left.islite != -1 && right.islite != -1)
    {
        temp.islite = 1;
        if (_tn->left != NULL)
            // temp.min= min(left.min)
            temp.min = left.min;
        if (_tn->right != NULL)
            temp.max = right.max;
    }
    // incase of descending lite tree
    else if (left.min > _tn->value && _tn->value > right.max && left.islite != 1 && right.islite != 1)
    {
        temp.islite = -1;
        if (_tn->right != NULL)
            temp.min = right.min;
        if (_tn->left != NULL)
            temp.max = left.max;
    }
    // if none of the above matches , then it is not a lite tree
    else
    {
        temp.min = min(left.min, min(right.min, _tn->value));
        temp.max = max(left.max, max(right.max, _tn->value));
        temp.islite = 0;
        return temp;
    }

    // sum of the tree rooted at _tn
    ll sum = _tn->value + left.sum + right.sum;

    // updating the value of ans
    *a = min(*a, sum);
    temp.sum = sum;

    return temp;
}

void DestroyTree(TreeNode _t)
{
    if (_t == NULL)
    {
        return;
    }
    DestroyTree(_t->left);
    DestroyTree(_t->right);
    free(_t);
    return;
}
//////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////Queue.c
Queue *InitQueue()
{
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    temp->top = NULL;
    temp->bottom = NULL;
    temp->size = 0;
    return temp;
}

int QueueIsEmpty(const Queue *const _s)
{
    return (_s->top == NULL);
}

ElementType QueueDequeue(Queue *_s)
{
    /*if (QueueIsEmpty(_s))
        return NOELEMENT;*/
    QueueNode *temp = _s->bottom;
    _s->bottom = _s->bottom->up;
    if (_s->bottom)
        _s->bottom->down = NULL;
    else
        _s->top = _s->bottom;
    ElementType tempele = temp->x;
    free(temp);
    _s->size--;
    return tempele;
}

void QueueEnqueue(Queue *_s, ElementType x)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    assert(temp != NULL);
    temp->down = _s->top;
    temp->x = x;
    temp->up = NULL;
    if (QueueIsEmpty(_s))
    {
        _s->top = temp;
        _s->bottom = temp;
    }
    else
    {
        _s->top->up = temp;
        _s->top = temp;
    }
    _s->size++;
    return;
}

ElementType QueueFront(const Queue *const _s)
{
    /*if (QueueIsEmpty(_s))
        return NOELEMENT;*/
    return _s->bottom->x;
}

int QueueSize(const Queue *const _s)
{
    return _s->size;
    int count = 0;
    QueueNode *iter = _s->top;
    while (iter)
    {
        iter = iter->down;
        count++;
    }
    return count;
}
/////////////////////////////////////////////////////////////////////