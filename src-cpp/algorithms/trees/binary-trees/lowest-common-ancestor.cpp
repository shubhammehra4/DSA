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
TreeNode *lowestCommonAncestor(TreeNode *root, int a, int b)
{
    if (root == nullptr)
        return nullptr;

    if (a == root->val || b == root->val)
        return root;

    if ((a <= root->val && b > root->val) || (b <= root->val && a > root->val))
        return root;

    if (root->val > max(a, b))
        return lowestCommonAncestor(root->left, a, b);

    return lowestCommonAncestor(root->right, a, b);
}