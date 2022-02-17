#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> breadthFirstSearch(TreeNode *root)
{
    if (root == nullptr)
        return {};

    queue<TreeNode *> q;

    vector<int> res;
    q.push(root);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        res.push_back(node->val);

        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }

    return res;
}