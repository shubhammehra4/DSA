#include <bits/stdc++.h>
using namespace std;

class BST {
    public:
        int data;
        BST *left, *right;
        BST() : data (0), left (NULL), right (NULL) {};
        BST (int);

        BST* Insert (BST*, int);
        BST* LowestCommonAncestor (BST*, int, int);
}*root = NULL, *root2 = NULL;

BST::BST (int value)
{
    data = value;
    left = right = NULL;
}

BST* BST::Insert (BST *p, int value)
{
    if (!p)
        return new BST (value);

    if (value > p->data)
        p->right = Insert (p->right, value);
    else
        p->left = Insert (p->left, value);

    return p;
}

BST* BST::LowestCommonAncestor (BST *p, int a, int b)
{
    if (p == NULL)
        return NULL;

    if (a == p->data || b == p->data) // considering there are no duplicate values
        return p;
    else if ( (a <= p->data && b > p->data) || (b <= p->data && a > p->data) )
        return p;
    else if (p->data > max (a, b) )
        return LowestCommonAncestor (p->left, a, b);
    else
        return LowestCommonAncestor (p->right, a, b);
}

int main()
{
    int h = 0;
    BST b1, b2;
    root = b1.Insert (root, 46);
    b1.Insert (root, 24);
    b1.Insert (root, 22);
    b1.Insert (root, 26);
    b1.Insert (root, 30);
    b1.Insert (root, 49);
    b1.Insert (root, 47);
    b1.Insert (root, 90);
    b1.Insert (root, 80);
    cout << b1.LowestCommonAncestor (root, 22, 24)->data;
    return 0;
}