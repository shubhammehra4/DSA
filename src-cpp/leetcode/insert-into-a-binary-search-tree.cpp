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
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    auto curr = root;
    auto node = new TreeNode(val);

    if (root == nullptr)
        return node;

    while (curr != nullptr)
    {
        if (curr->val > val)
        {
            if (curr->left == nullptr)
            {
                curr->left = node;
                return root;
            }

            curr = curr->left;
        }
        else
        {
            if (curr->right == nullptr)
            {
                curr->right = node;
                return root;
            }

            curr = curr->right;
        }
    }

    return root;
}

// recursive-2
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);

    if (root->left == nullptr && root->val > val)
    {
        root->left = new TreeNode(val);
        return root;
    }

    if (root->right == nullptr && root->val < val)
    {
        root->right = new TreeNode(val);
        return root;
    }

    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

// recursive
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);

    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}