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
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};

    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto [node, point] = q.front();
        q.pop();
        auto [x, y] = point;

        nodes[x][y].insert(node->val);

        if (node->left != nullptr)
            q.push({node->left, {x - 1, y + 1}});

        if (node->right != nullptr)
            q.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
            col.insert(end(col), begin(q.second), end(q.second));

        ans.push_back(move(col));
    }

    return ans;
}

// dfs
void traverse(TreeNode *root, int x, int y, map<int, map<int, multiset<int>>> &nodes)
{
    if (root == nullptr)
        return;

    nodes[x][y].insert(root->val);
    traverse(root->left, x - 1, y + 1, nodes);
    traverse(root->right, x + 1, y + 1, nodes);
}
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    traverse(root, 0, 0, nodes);
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
            col.insert(end(col), begin(q.second), end(q.second));

        ans.push_back(move(col));
    }

    return ans;
}
