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

// recursive backtracking 1
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> res;
    vector<int> path;

    function<void(TreeNode *, int)> pathSumUtil = [&path, &res, &pathSumUtil](TreeNode *node, int targetSum) -> void
    {
        if (!node)
            return;

        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && targetSum == node->val)
            res.push_back(path);

        pathSumUtil(node->left, targetSum - node->val);
        pathSumUtil(node->right, targetSum - node->val);
        path.pop_back();
    };

    pathSumUtil(root, targetSum);

    return res;
}

// recursive backtracking 2
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return {};

    vector<vector<int>> res;
    vector<int> path;

    function<void(TreeNode *, int)> pathSumUtil =
        [&path, &res, &pathSumUtil](TreeNode *node, int targetSum) -> void
    {
        path.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr && targetSum == node->val)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }

        if (node->left != nullptr)
            pathSumUtil(node->left, targetSum - node->val);

        if (node->right != nullptr)
            pathSumUtil(node->right, targetSum - node->val);

        path.pop_back();
    };

    pathSumUtil(root, targetSum);

    return res;
}