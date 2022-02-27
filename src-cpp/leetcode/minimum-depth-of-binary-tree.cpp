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
int minDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    queue<TreeNode *> q, aux;
    q.push(root);
    int height = 0;

    while (!q.empty())
    {
        height++;
        int levelSize = q.size();
        while (levelSize--)
        {
            auto node = q.front();
            q.pop();

            if (node->left == nullptr && node->right == nullptr)
                return height;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return 1;
}

// recursive
int minDepth(TreeNode *root)
{

    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    if (root->left == nullptr)
        return minDepth(root->right) + 1;
    if (root->right == nullptr)
        return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}