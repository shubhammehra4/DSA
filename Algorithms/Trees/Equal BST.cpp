#include <bits/stdc++.h>
using namespace std;

class BST {
    public:
        int data;
        BST *left, *right;
        BST() : data (0), left (NULL), right (NULL) {};
        BST (int);

        BST* Insert (BST*, int);
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

bool sameTree (BST *t1, BST *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;

    if (t1 == NULL || t2 == NULL)
        return false;

    if (t1->data == t2->data && sameTree (t1->left, t2->left) && sameTree (t1->right, t2->right) )
        return true;

    return false;
}

int main()
{
    int h = 0;
    BST b1, b2;
    root = b1.Insert (root, 50);
    b1.Insert (root, 30);
    b1.Insert (root, 20);
    b1.Insert (root, 40);
    root2 = b2.Insert (root2, 50);
    b2.Insert (root2, 40);
    b2.Insert (root2, 20);
    b2.Insert (root2, 40);

    if (sameTree (root, root2) )
        cout << "Trees are equal";
    else
        cout << "Trees are not equal";

    return 0;
}