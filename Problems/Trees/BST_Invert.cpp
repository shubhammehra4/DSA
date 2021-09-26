#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;

    queue<TreeNode *> q;
    q.push(root);

    TreeNode *top, *tmp;
    while (!q.empty())
    {
        top = q.front();
        q.pop();
        tmp = top->left;
        top->left = top->right;
        top->right = tmp;

        if (top->left != nullptr)
            q.push(top->left);

        if (top->right != nullptr)
            q.push(top->right);
    }

    return root;
}

int main()
{
    return 0;
}