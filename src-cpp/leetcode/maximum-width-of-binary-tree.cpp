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
int widthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    unsigned long long maxWidth = 0;

    queue<pair<TreeNode *, unsigned long long>> q; // {node, nodeId}
    q.push({root, 1});

    while (!q.empty())
    {
        int levelSize = q.size();

        auto leftNodeId = q.front().second;
        auto rightNodeId = leftNodeId;

        while (levelSize--)
        {
            auto node = q.front().first;
            rightNodeId = q.front().second;
            q.pop();

            if (node->left != nullptr)
                q.push({node->left, rightNodeId * 2});

            if (node->right != nullptr)
                q.push({node->right, rightNodeId * 2 + 1});
        }

        maxWidth = max({maxWidth, rightNodeId + 1 - leftNodeId});
    }

    return (int)maxWidth;
}

// recursive
typedef unsigned long long ull;
int widthOfBinaryTree(TreeNode *root)
{
    unordered_map<ull, ull> mp;

    function<ull(TreeNode *, ull, ull)> dfs = [&](TreeNode *node, ull nodeId, ull depth) -> int
    {
        if (node == nullptr)
            return 0;

        if (mp.find(depth) == end(mp))
            mp[depth] = nodeId;

        auto leftChildWidth = dfs(node->left, nodeId * 2, depth + 1);
        auto rightChildWidth = dfs(node->right, nodeId * 2 + 1, depth + 1);

        return max({nodeId + 1 - mp[depth],
                    leftChildWidth, rightChildWidth});
    };

    return (int)dfs(root, 1, 0);
}