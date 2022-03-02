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

// iterative
bool isValidBST(TreeNode *root)
{
    long pre = LONG_MIN;
    stack<TreeNode *> todo;

    while (root || !todo.empty())
    {
        while (root)
        {
            todo.push(root);
            root = root->left;
        }

        root = todo.top();
        todo.pop();

        if (root->val <= pre)
            return false;

        pre = root->val;
        root = root->right;
    }

    return true;
}

// recursive
bool isValidBST(TreeNode *root)
{
    function<bool(TreeNode *, long, long)> valid = [&valid](TreeNode *root, long min, long max) -> bool
    {
        if (root == nullptr)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return valid(root->left, min, root->val) && valid(root->right, root->val, max);
    };

    return valid(root, LONG_MIN, LONG_MAX);
}
