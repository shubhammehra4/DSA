#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    if (!root)
        return NULL;

    if (root->left)
    {
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);
    }
    return root;
}

Node *connectIterative(Node *root)
{
    if (!root)
        return;

    Node *pre = root;
    Node *cur = NULL;

    while (pre->left)
    {
        cur = pre;
        while (cur)
        {
            cur->left->next = cur->right;
            if (cur->next)
                cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }

    return root;
}

int main()
{
    return 0;
}