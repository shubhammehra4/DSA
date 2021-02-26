#include <bits/stdc++.h>
using namespace std;

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
        int RecSearch (BST*, int);
        int IterSearch (BST*, int);
        void inOrder (BST *);
        void preOrder (BST *);
        void postOrder (BST *);
}*root = NULL;

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

BST* BST::Delete (BST *p, int key)
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


int BST::Height (BST *p)
{
    int x, y;

    if (p == NULL)
        return 0;

    x = Height ( p->left );
    y = Height ( p->right );
    return x > y ? x + 1 : y + 1;
}

BST* BST::InPre (BST *p)
{
    while (p && p->right != NULL)
        p = p->right;

    return p;
}

BST* BST::InSucc (BST *p)
{
    while (p && p->left != NULL)
        p = p->left;

    return p;
}

int BST::RecSearch (BST* p, int key)
{
    if (p == NULL)
        return -1;

    if (p->data == key)
        return p->data;
    else if (p->data < key)
        return RecSearch (p->right, key);
    else
        return RecSearch (p->left, key);
}

int BST::IterSearch (BST* p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p->data;
        else if (p->data < key)
            p = p->right;
        else
            p = p->left;
    }

    return -1;
}

void BST::inOrder (BST *p)
{
    if (!p)
        return;

    inOrder (p->left);
    cout << p->data << " ";
    inOrder (p->right);
}

void BST::preOrder (BST *p)
{
    if (!p)
        return ;

    cout << p->data << " ";
    preOrder (p->left);
    preOrder (p->right);
}

void BST::postOrder (BST *p)
{
    if (!p)
        return;

    postOrder (p->left);
    postOrder (p->right);
    cout << p->data << " ";
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
    b.inOrder (root);
    cout << endl;
    b.preOrder (root);
    cout << endl;
    b.postOrder (root);
    cout << "\n";
    cout << b.IterSearch (root, 60) << "\n";
    b.Delete (root, 60);
    b.inOrder (root);
    cout << "\n";
    cout << b.Height (root);
    return 0;
}