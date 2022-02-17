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

bool equalTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;

    if (root1->val == root2->val)
        return equalTrees(root1->left, root2->left) && equalTrees(root1->right, root2->right);

    return false;
}