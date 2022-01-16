#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int val) : val(val), left(NULL), right(NULL) {}
};

class BTree
{
    Node *root;

    BTree() : root(NULL) {}
    BTree(int val) : root(new Node(val)) {}

public:
    Node *insert(int val)
    {
        Node *curr = root;

        while (curr->left && curr->right)
        {
            if (val > curr->val)
                curr = curr->right;
            else
                curr = curr->left;
        }

        curr->val = val;
        return curr;
    }
};