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

// bfs
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    queue<TreeNode *> q;
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

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return height;
}

// dfs
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    auto leftDepth = maxDepth(root->left);
    auto rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}
