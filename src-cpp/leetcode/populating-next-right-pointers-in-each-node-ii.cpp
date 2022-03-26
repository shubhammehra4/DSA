#include <bits/stdc++.h>
using namespace std;

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

// iterative
Node *connect(Node *root)
{
    if (root == nullptr)
        return nullptr;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        Node *nextRightNode = nullptr;

        while (levelSize--)
        {
            auto node = q.front();
            q.pop();

            node->next = nextRightNode;
            nextRightNode = node;

            if (node->right)
                q.push(node->right);

            if (node->left)
                q.push(node->left);
        }
    }

    return root;
}

// naive
Node *connect(Node *root)
{
    if (root == nullptr)
        return root;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        list<Node *> level;

        while (levelSize--)
        {
            auto node = q.front();
            q.pop();
            level.push_front(node);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        Node *nextRightPtr = nullptr;
        for (auto &n : level)
        {
            n->next = nextRightPtr;
            nextRightPtr = n;
        }
    }

    return root;
}