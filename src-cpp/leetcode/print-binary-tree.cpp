#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void dfs(TreeNode *root, int l, int r, int h, vector<vector<string>> &res)
{
    if (root == NULL || l > r)
        return;

    int mid = (l + r) / 2;

    res[h][mid] = to_string(root->val);
    dfs(root->left, l, mid - 1, h + 1, res);
    dfs(root->right, mid + 1, r, h + 1, res);
}

vector<vector<string>> printTree(TreeNode *root)
{
    int h = height(root);
    int c = pow(2, h) - 1;

    vector<vector<string>> res(h, vector<string>(c));
    dfs(root, 0, c - 1, 0, res);

    return res;
}