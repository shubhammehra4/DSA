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
bool isEvenOddTree(TreeNode *root)
{
    if (root == nullptr) // optional as per constraints
        return true;

    queue<TreeNode *> q;
    q.push(root);

    bool isEvenLevel = true;

    while (!q.empty())
    {
        int levelSize = q.size();
        auto prevVal = isEvenLevel ? INT_MIN : INT_MAX;

        while (levelSize--)
        {
            auto node = q.front();
            q.pop();

            if (isEvenLevel && (node->val <= prevVal || node->val % 2 == 0))
                return false;

            if (!isEvenLevel && (node->val >= prevVal || node->val % 2 == 1))
                return false;

            prevVal = node->val;

            if (node->left != nullptr)
                q.push(node->left);

            if (node->right != nullptr)
                q.push(node->right);
        }
        isEvenLevel = !isEvenLevel;
    }

    return true;
}

// dfs
bool isEvenOddTree(TreeNode *root)
{
    unordered_map<int, int> prevVal;

    function<bool(TreeNode *, int)> dfsUtil = [&prevVal, &dfsUtil](TreeNode *node, int level) -> bool
    {
        if (node == nullptr)
            return true;

        bool isEvenLevel = !(level & 1);

        if (isEvenLevel && !(node->val & 1))
            return false;

        if (!isEvenLevel && node->val & 1)
            return false;

        if (prevVal.find(level) != end(prevVal))
        {
            if (isEvenLevel && node->val <= prevVal[level])
                return false;

            if (!isEvenLevel && node->val >= prevVal[level])
                return false;
        }

        prevVal[level] = node->val;

        return dfsUtil(node->left, level + 1) && dfsUtil(node->right, level + 1);
    };

    return dfsUtil(root, 0);
}