#include "treenode.h"
#include "tree.h"
#include "queue.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

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

    // when the childeren itself are not lite trees / one of them is ascending and the other descending
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
        // temp.min = min(left.min, min(right.min, _tn->value));
        // temp.max = max(left.max, max(right.max, _tn->value));
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

/*void findminrecursive(TreeNode _tn)
{
    if (_tn->left == NULL && _tn->right == NULL)
    {
        _tn->islite = 2;
        _tn->sum = _tn->value;
        _tn->currsum =_tn->value;
        _tn->min = _tn->value;
        _tn->max = _tn->value;
        return;
    }
    else if (_tn->left == NULL)
    {
        findminrecursive(_tn->right);
        int check;
        if (_tn->right->islite == 1 && _tn->right->min > _tn->value)
        {
            check = 1;
            _tn->min = min(_tn->value, _tn->right->min);
            _tn->max = max(_tn->value, _tn->right->max);
            _tn->currsum = _tn->right->currsum + _tn->value;
            _tn->sum = min(_tn->right->sum,_tn->currsum);
        }
        else if (_tn->right->islite == -1 && _tn->right->max < _tn->value)
        {
            check = -1;
            _tn->min = min(_tn->value, _tn->right->min);
            _tn->max = max(_tn->value, _tn->right->max);
            _tn->currsum = _tn->right->currsum + _tn->value;
            _tn->sum=min(_tn->right->sum,_tn->currsum);
        }
        else if (_tn->right->islite == 0)
        {
            //_tn->min=min(_tn->value,_tn->right->min);
            //_tn->max=max(_tn->value,_tn->right->max);
            _tn->islite = 0;
            _tn->min = min(_tn->value, _tn->right->min);
            _tn->max = max(_tn->value, _tn->right->max);
            //_tn->currsum = _tn->right->currsum + _tn->value;
            _tn->sum=_tn->right->sum;//,_tn->currsum);
            return;
        }
        else if (_tn->right->islite == 2)
        {
            _tn->islite = _tn->value < _tn->right->value ? 1 : -1;
            _tn->min = min(_tn->value, _tn->right->min);
            _tn->max = max(_tn->value, _tn->right->max);
            _tn->currsum = _tn->right->currsum + _tn->value;
            _tn->sum=min(_tn->right->sum,_tn->currsum);
        }
        else
        {
            _tn->islite = 0;
            _tn->min = min(_tn->value, _tn->right->min);
            _tn->max = max(_tn->value, _tn->right->max);
           // _tn->currsum = _tn->right->currsum + _tn->value;
            _tn->sum=_tn->right->sum;//,_tn->currsum);
            return;
        }
        //if (_tn->right->islite == 0 || check * _tn->right->islite == -1)
        //{
         //   _tn->islite = 0;
         //   return;
        //}
        //else
        //{
         //   _tn->sum = _tn->sum > _tn->right->sum ? _tn->right->sum : _tn->sum;
         //   _tn->islite = check;
         //   return;
        //}
    }
    else if (_tn->right == NULL)
    {
        findminrecursive(_tn->left);
        int check;
        if (_tn->left->islite == 1 && _tn->left->max < _tn->value)
        {
            check = 1;
            _tn->min = min(_tn->value, _tn->left->min);
            _tn->max = max(_tn->value, _tn->left->max);
            _tn->currsum = _tn->left->currsum + _tn->value;
            _tn->sum=min(_tn->left->sum,_tn->currsum);
            //_tn->sum = _tn->left->sum + _tn->value;
        }
        else if (_tn->left->islite == -1 && _tn->left->min > _tn->value)
        {
            check = -1;
            _tn->min = min(_tn->value, _tn->left->min);
            _tn->max = max(_tn->value, _tn->left->max);
             _tn->currsum = _tn->left->currsum + _tn->value;
            _tn->sum=min(_tn->left->sum,_tn->currsum);
        }
        else if (_tn->left->islite == 0)
        {
            //_tn->min=min(_tn->value,_tn->right->min);
            //_tn->max=max(_tn->value,_tn->right->max);
            _tn->islite = 0;
            _tn->min = min(_tn->value, _tn->left->min);
            _tn->max = max(_tn->value, _tn->left->max);
             //_tn->currsum = _tn->left->currsum + _tn->value;
            _tn->sum=_tn->left->sum;//,_tn->currsum);
            return;
        }
        else if (_tn->left->islite == 2)
        {
            _tn->islite = _tn->value > _tn->left->value ? 1 : -1;
            _tn->min = min(_tn->value, _tn->left->min);
            _tn->max = max(_tn->value, _tn->left->max);
            _tn->currsum = _tn->left->currsum + _tn->value;
            _tn->sum=min(_tn->left->sum,_tn->currsum);
        }
        else
        {
            _tn->islite = 0;
            _tn->min = min(_tn->value, _tn->left->min);
            _tn->max = max(_tn->value, _tn->left->max);
            //_tn->currsum = _tn->left->currsum + _tn->value;
            _tn->sum=_tn->left->sum;//,_tn->currsum;
            return;
        }
    }
    else
    {
        findminrecursive(_tn->left);
        findminrecursive(_tn->right);
        if (_tn->left->islite == 2)
        {
            if (_tn->right->islite == 2)
            {
                if (_tn->left->value < _tn->value && _tn->value < _tn->right->value)
                {
                    _tn->islite = 1;
                }
                else if (_tn->left->value > _tn->value && _tn->value > _tn->right->value)
                {
                    _tn->islite = -1;
                }
                else
                {
                    _tn->islite = 0;
                }
                _tn->min = min(_tn->right->min,min(_tn->value,_tn->left->value));
                _tn->max = max(_tn->right->max,max(_tn->value,_tn->left->value));
                _tn->currsum
            }
            else
            {
                if (_tn->left->value < _tn->value && _tn->right->min > _tn->value && _tn->right->islite == 1)
                {
                    _tn->islite = 1;
                }
                else if (_tn->left->value > _tn->value && _tn->right->max < _tn->value && _tn->right->islite == -1)
                {
                    _tn->islite = -1;
                }
                else
                {
                    _tn->islite = 0;
                }
            }
        }
        else if (_tn->right->islite == 2)
        {
            if (_tn->right->value > _tn->value && _tn->left->max < _tn->value && _tn->left->islite == 1)
            {
                _tn->islite = 1;
            }
            else if (_tn->right->value < _tn->value && _tn->left->min > _tn->value && _tn->left->islite == -1)
            {
                _tn->islite = -1;
            }
            else
            {
                _tn->islite = 0;
            }
        }
        else
        {
            if (_tn->left->max < _tn->value && _tn->value < _tn->right->min && _tn->left->islite == 1 && _tn->right->islite == 1)
            {
                _tn->islite = 1;
            }
            else if (_tn->left->min > _tn->value && _tn->value > _tn->right->max && _tn->left->islite == -1 && _tn->right->islite == -1)
            {
                _tn->islite = -1;
            }
            else
            {
                _tn->islite = 0;
            }
        }
    }
}*/