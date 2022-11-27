#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

//////////////////////////////////////////
typedef struct treenode* TreeNode;
typedef TreeNode ElementType;
typedef long long ll;

struct treenode{
    int value;
    struct treenode* left;
    struct treenode* right;
    // ll min;
    // ll max;
    // ll sum;
    // ll currsum;
    int children;
    //int islite;
};

TreeNode InitTreeNode(int _x);
/////////////////////////////////////////////


///////////////////////////////queue header
typedef struct Queue Queue;
typedef struct QueueNode QueueNode;

struct Queue{
    size_t size;
    QueueNode* top;
    QueueNode* bottom;
};

struct QueueNode{
    ElementType x;
    QueueNode* down;
    QueueNode* up;
};

Queue* InitQueue();

int QueueIsEmpty(const Queue* const _s);

ElementType QueueDequeue(Queue* _s);
void QueueEnqueue(Queue* _s,ElementType x);

ElementType QueueFront(const Queue* const _s);

int QueueSize(const Queue* const _s);
/////////////////////////////////////








///////////////////////////////////////
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





/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
typedef struct tree* Tree;
struct tree{
    TreeNode root;
};

typedef struct returnstruct{
    ll min;
    ll max;
    ll sum;
    int islite;
}ReturnStruct;

Tree InitTree(void);
int IsTreeEmpty(Tree _t);
Tree GenerateTreeFromLevelOrder(int n,int A[]);
ll findMinNoice(Tree _t);
ReturnStruct findminrecursive(TreeNode _tn,ll* a);
void DestroyTree(TreeNode _t);
//////////////////////////////////////////////////////////












///////////////////////////////////////////////////////////
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
    Queue *order = InitQueue();
    Tree BinaryTree = InitTree();

    //generate a new node for root
    TreeNode tempnode = InitTreeNode(A[0]);
    QueueEnqueue(order, tempnode);
    //initalise root
    BinaryTree->root = tempnode;
    int pos = 1;
    while (pos < n)
    {
        TreeNode tempnode = InitTreeNode(A[pos]); //create a new node with a value of A[pos]
        if (A[pos] != 0)
            QueueEnqueue(order, tempnode);
        if (QueueFront(order)->children == 0)
        {
            if (tempnode->value != 0)
                QueueFront(order)->left = tempnode;
            QueueFront(order)->children++;
        }
        else if (QueueFront(order)->children == 1)
        {
            if (tempnode->value != 0)
                QueueFront(order)->right = tempnode;
            QueueFront(order)->children++;
            QueueDequeue(order);
        }
        pos++;
    }
    return BinaryTree;
}

ll findMinNoice(Tree _t)
{
    ll ans = INT_MAX;
    /*ReturnStruct temp;
    temp.islite = 0;
    temp.max = INT_MIN;
    temp.min = INT_MAX;
    temp.sum = 0;*/
    findminrecursive(_t->root, &ans);
    return ans;
}

ReturnStruct findminrecursive(TreeNode _tn, ll *a)
{
    ReturnStruct temp;
    temp.islite = 0;
    temp.max = INT_MIN;
    temp.min = INT_MAX;
    temp.sum = 0;
    if (_tn == NULL)
    {
        temp.islite = 2;
        return temp;
    }
    temp.max = _tn->value;
    temp.min = _tn->value;
    ReturnStruct left = findminrecursive(_tn->left, a);
    ReturnStruct right = findminrecursive(_tn->right, a);

    if (left.islite == 0 || right.islite == 0 || left.islite * right.islite == -1)
    {
        return temp;
    }
    /*if (left.islite * right.islite == -1)
        return temp;*/

    /*if ((_tn->value>left.max&&_tn->value>right.min)||(_tn->value<left.min&&_tn->value>right.max))
        return temp;*/

    if (_tn->left == NULL && _tn->right == NULL)
        temp.islite = 2;
    else if (left.max < _tn->value && _tn->value < right.min && left.islite != -1 && right.islite != -1)
    {
        temp.islite = 1;
        if (_tn->left != NULL)
            // temp.min= min(left.min)
            temp.min = left.min;
        if (_tn->right != NULL)
            temp.max = right.max;
    }

    else if (left.min > _tn->value && _tn->value > right.max && left.islite != 1 && right.islite != 1)
    {
        temp.islite = -1;
        if (_tn->right != NULL)
            temp.min = right.min;
        if (_tn->left != NULL)
            temp.max = left.max;
    }
    else
    {
        temp.min=min(left.min,min(right.min,_tn->value));
        temp.max=max(left.max,max(right.max,_tn->value));
        temp.islite = 0;
        return temp;
    }
     ll sum = _tn->value + left.sum + right.sum;
    *a = min(*a, sum);
    temp.sum = sum;
    return temp;
}

void DestroyTree(TreeNode _t){
    if(_t==NULL){
        return;
    }
    DestroyTree(_t->left);
    DestroyTree(_t->right);
    free(_t);
    return;
}
///////////////////////////////////////////////////////////////////














/////////////////////////////queue implementation
Queue* InitQueue(){
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    temp->top=NULL;
    temp->bottom=NULL;
    temp->size=0;
    return temp;
}

int QueueIsEmpty(const Queue* const _s)
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
        _s->top=_s->bottom;
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
    if (QueueIsEmpty(_s)){
        _s->top = temp;
        _s->bottom=temp;
    }else{
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
////////////////////////////////////

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
    }
}