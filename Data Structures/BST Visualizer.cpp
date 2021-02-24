#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

class BST {
    private:
        int data;
        BST *left, *right;
    public:
        BST() : data (0), left (NULL), right (NULL) {};
        BST (int);
        BST* Insert (BST*, int);
        BST* Delete (BST *, int);
        int Height (BST *);
        BST* InPre (BST *);
        BST* InSucc (BST *);
        void print2DUtil (BST *, int );
        void print2D (BST *);
}*root = NULL;

BST :: BST (int value)
{
    data = value;
    left = right = NULL;
}

int BST :: Height (BST *p)
{
    int x, y;

    if (p == NULL)
        return 0;

    x = Height ( p->left );
    y = Height ( p->right );
    return x > y ? x + 1 : y + 1;
}

BST* BST :: InPre (BST *p)
{
    while (p && p->right != NULL)
        p = p->right;

    return p;
}

BST* BST :: InSucc (BST *p)
{
    while (p && p->left != NULL)
        p = p->left;

    return p;
}

BST* BST :: Insert (BST *p, int value)
{
    if (!p)
    {
        return new BST (value);
    }

    if (value > p->data)
        p->right = Insert (p->right, value);
    else
        p->left = Insert (p->left, value);

    return p;
}

BST* BST :: Delete (BST *p, int key)
{
    BST *q;

    if (p == NULL)
        return NULL;

    if (p->left == NULL && p->right == NULL)
    {
        free (p);
        return NULL;
    }

    if (key < p->data)
        p->left = Delete (p->left, key);
    else if (key > p->data)
        p->right = Delete (p->right, key);
    else
    {
        if (Height (p->left) > Height (p->right) )
        {
            q = InPre (p->left); //Rightmost child of left sub-tree
            p->data = q->data;
            p->left = Delete (p->left, q->data);
        }

        else
        {
            q = InSucc (p->right); //leftmost child of right sub-tree
            p->data = q->data;
            p->right = Delete (p->right, q->data);
        }
    }

    return p;
}

void BST :: print2DUtil (BST *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;
    print2DUtil (root->right, space);
    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";

    cout << root->data << "\n";
    print2DUtil (root->left, space);
}

void BST :: print2D (BST *root)
{
    print2DUtil (root, 0);
}

int main()
{
    BST b;
    root = b.Insert (root, 50);
    b.Insert (root, 30);
    b.Insert (root, 20);
    b.Insert (root, 40);
    b.Insert (root, 70);
    b.Insert (root, 60);
    b.Insert (root, 80);
    b.Delete (root, 30);
    b.print2D (root);
    return 0;
}