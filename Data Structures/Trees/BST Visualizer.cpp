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
        void print2DUtil (BST *, int );
        void print2D (BST *);
}*root = NULL;

BST::BST (int value)
{
    data = value;
    left = right = NULL;
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
    b.Insert (root, 90);
    b.print2D (root);
    return 0;
}