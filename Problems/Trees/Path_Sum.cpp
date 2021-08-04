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

bool hasPathSum(TreeNode *root, int sum)
{
    if (!root)
        return false;

    if (root->left == NULL and root->right == NULL)
        if (sum == root->val)
            return true;

    int rest = sum - root->val;
    return hasPathSum(root->left, rest) || hasPathSum(root->right, rest);
}

int main()
{
    return 0;
}