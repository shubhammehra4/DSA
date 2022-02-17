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

vector<int> largestValues(TreeNode *root)
{
    if (root == nullptr)
        return {};

    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        int maxVal = INT_MIN;
        while (levelSize--)
        {
            auto node = q.front();
            q.pop();
            maxVal = max(maxVal, node->val);

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }

        res.push_back(maxVal);
    }

    return res;
}
