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

int maxLevelSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    queue<TreeNode *> q;
    q.push(root);
    int level = 1;

    int levelSum = INT_MIN;
    int resLevel = -1;

    while (!q.empty())
    {
        int levelSize = q.size();
        int sum = 0;
        while (levelSize--)
        {
            auto node = q.front();
            sum += node->val;
            q.pop();

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }

        if (sum > levelSum)
        {
            resLevel = level;
            levelSum = sum;
        }
        level++;
    }

    return resLevel;
}

// Alter - bfs
int maxLevelSum(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    vector<TreeNode *> q{root};
    int level = 1;

    int levelSum = INT_MIN;
    int resLevel = -1;

    while (!q.empty())
    {
        vector<TreeNode *> q1;
        int sum = 0;
        for (auto node : q)
        {

            sum += node->val;

            if (node->left != nullptr)
                q1.push_back(node->left);
            if (node->right != nullptr)
                q1.push_back(node->right);
        }

        if (sum > levelSum)
        {
            resLevel = level;
            levelSum = sum;
        }
        level++;
        swap(q, q1);
    }

    return resLevel;
}

// Alter - dfs
vector<int> sums;
void dfs(TreeNode *node, size_t lvl)
{
    if (node != nullptr)
    {
        sums.resize(max(size(sums), lvl)); // add level if not present
        sums[lvl - 1] += node->val;
        dfs(node->left, lvl + 1);
        dfs(node->right, lvl + 1);
    }
}

int maxLevelSum(TreeNode *root)
{
    dfs(root, 1);
    return distance(begin(sums), max_element(begin(sums), end(sums))) + 1; // index of max element
}
