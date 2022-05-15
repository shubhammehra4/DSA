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

// as per question
bool checkTree(TreeNode *root)
{
    return root->val == root->left->val + root->right->val;
}

// general solution
bool checkTree(TreeNode *root)
{
    if (root == nullptr || (!root->left && !root->right))
        return true;

    int target = 0;
    if (root->left)
        target += root->left->val;
    if (root->right)
        target += root->right->val;

    return root->val == target && checkTree(root->left) && checkTree(root->right);
}