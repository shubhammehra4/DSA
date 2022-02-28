#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// iterative
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;

    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty())
    {
        auto left = q.front();
        q.pop();
        auto right = q.front();
        q.pop();

        if (left == nullptr && right == nullptr)
            continue;

        if (left == nullptr || right == nullptr)
            return false;

        if (left->val != right->val)
            return false;

        q.push(left->left);
        q.push(right->right);

        q.push(left->right);
        q.push(right->left);
    }

    return true;
}

bool isMirror(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;

    if (p == nullptr || q == nullptr)
        return false;

    if (p->val != q->val)
        return false;

    return isMirror(p->left, q->right) && isMirror(p->right, q->left);
}

// recursive
bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;

    return isMirror(root->left, root->right);
}
