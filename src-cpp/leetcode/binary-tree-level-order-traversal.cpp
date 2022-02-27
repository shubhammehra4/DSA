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
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;

    if (root == nullptr)
        return res;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> level;
        while (levelSize--)
        {
            auto node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }

        res.push_back(level);
    }

    return res;
}

// recursive
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;

    function<void(TreeNode *, int)> levelorderUtil = [&res, &levelorderUtil](TreeNode *node, int depth) -> void
    {
        if (node == nullptr)
            return;

        if (depth >= res.size())
            res.push_back(vector<int>());

        res[depth].push_back(node->val);

        levelorderUtil(node->left, depth + 1);
        levelorderUtil(node->right, depth + 1);
    };

    levelorderUtil(root, 0);

    return res;
}