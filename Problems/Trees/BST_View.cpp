#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rightSideHelper(TreeNode *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;

    if (res.size() < level)
        res.push_back(root->val);

    rightSideHelper(root->right, level + 1, res);
    rightSideHelper(root->left, level + 1, res);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> view;
    rightSideHelper(root, 0, view);
    return view;
}

void leftSideHelper(TreeNode *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;

    if (res.size() < level)
        res.push_back(root->val);

    leftSideHelper(root->left, level + 1, res);
    leftSideHelper(root->right, level + 1, res);
}

vector<int> leftSideView(TreeNode *root)
{
    vector<int> view;
    leftSideHelper(root, 0, view);
    return view;
}

void topSideHelper(TreeNode *root, int dist, int level, auto &m)
{
    if (root == NULL)
        return;

    // if the current level is less than the maximum level seen so far
    // for the same horizontal distance, or if the horizontal distance
    // is seen for the first time, update the map
    if (m.find(dist) == m.end() || level < m[dist].second)
        m[dist] = {root->val, level};

    topSideHelper(root->left, dist - 1, level + 1, m);
    topSideHelper(root->right, dist + 1, level + 1, m);
}

vector<int> topSideView(TreeNode *root)
{
    vector<int> view;
    // `key` —> relative horizontal distance of the node from the root node, and
    // `value` —> pair containing the node's value and its level
    map<int, pair<int, int>> m;
    topSideHelper(root, 0, 0, m);

    for (auto it : m)
        view.push_back(it.second.first);

    return view;
}

int main()
{
    return 0;
}