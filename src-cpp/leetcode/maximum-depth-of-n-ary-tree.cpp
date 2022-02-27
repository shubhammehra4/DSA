#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}
    Node(int _val)
    {
        val = _val;
    }
    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// iterative
int maxDepth(Node *root)
{
    if (root == nullptr)
        return 0;

    queue<Node *> q;
    int height = 0;
    q.push(root);

    while (!q.empty())
    {
        height++;
        int levelSize = q.size();

        while (levelSize--)
        {
            auto node = q.front();
            q.pop();

            for (auto &child : node->children)
                if (child)
                    q.push(child);
        }
    }

    return height;
}

// recursive
int maxDepth(Node *root)
{
    if (root == nullptr)
        return 0;

    int depth = 0;
    for (auto child : root->children)
        depth = max(depth, maxDepth(child));

    return 1 + depth;
}