#include <bits/stdc++.h>
using namespace std;

class BTreeNode
{
    int *keys;     // An array of keys
    int t;         // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;         // Current number of keys
    bool leaf;     // Is true when node is leaf. Otherwise false
public:
    BTreeNode(int _t, bool _leaf) // Copy the given minimum degree and leaf property
    {
        t = _t;
        leaf = _leaf;
        keys = new int[2 * t - 1];
        C = new BTreeNode *[2 * t];
        n = 0;
    }
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
    // A utility function to split the child y of this node. i is index of y in
    // child array C[]. The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);

    void traverse();
    BTreeNode *search(int k);
    friend class BTree;
};

void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!leaf)
            C[i]->traverse();
        cout << " " << keys[i];
    }

    if (!leaf)
        C[i]->traverse();
}

BTreeNode *BTreeNode::search(int k)
{
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf)
        return NULL;

    return C[i]->search(k); // search in children
}

void BTreeNode::insertNonFull(int k)
{
    int i = n - 1;
    if (leaf)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1)
        {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y)
{
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];

    n = n + 1;
}

class BTree
{
    BTreeNode *root; // Pointer to root node
    int t;           // Minimum degree
public:
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }
    void traverse()
    {
        if (root != NULL)
            root->traverse();
    }

    BTreeNode *search(int k)
    {
        return (root == NULL) ? NULL : root->search(k);
    }
    void insert(int k);
};

void BTree::insert(int k)
{
    if (root == NULL)
    {
        root = new BTreeNode(t, true); // New Tree
        root->keys[0] = k;
        root->n = 1;
    }
    else
    {
        if (root->n == 2 * t - 1)
        {
            BTreeNode *s = new BTreeNode(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

int main()
{
    BTree t(3); // A B-Tree with minium degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constucted tree is ";
    t.traverse();

    int k = 6;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";

    k = 15;
    (t.search(k) != NULL) ? cout << "\nPresent" : cout << "\nNot Present";

    return 0;
}
