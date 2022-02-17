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

// DFS
TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    auto temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        auto tmp = top->left;
        top->left = top->right;
        top->right = tmp;

        if (top->left != nullptr)
            q.push(top->left);

        if (top->right != nullptr)
            q.push(top->right);
    }

    return root;
}