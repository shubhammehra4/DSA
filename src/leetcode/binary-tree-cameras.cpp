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

enum Case
{
    HAS_CAMERA,
    COVERED,
    NEED_MONITOR
};

int ans = 0;

int minCameraCover(TreeNode *root)
{
    auto rootStatus = dfs(root);

    if (rootStatus == NEED_MONITOR)
        ans++;

    return ans;
}

Case dfs(TreeNode *node)
{
    if (node == nullptr)
        return COVERED;

    auto left = dfs(node->left);
    auto right = dfs(node->right);

    if (left == NEED_MONITOR || right == NEED_MONITOR)
    {
        ans++;
        return HAS_CAMERA;
    }

    if (left == HAS_CAMERA || right == HAS_CAMERA)
        return COVERED;

    return NEED_MONITOR;
}
