#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int id;
    TreeNode *parent;
    vector<TreeNode *> children;
    TreeNode(int _id, TreeNode *_parent) : id(_id), parent(_parent), children(vector<TreeNode *>()) {}
};

vector<int> centerOfTree(vector<vector<int>> &adjLists)
{
    int n = adjLists.size();
    vector<int> degree(n, 0);
    vector<int> leaves;

    for (int i = 0; i < n; i++)
    {
        degree[i] = adjLists[i].size();
        if (degree[i] <= 1)
        {
            leaves.push_back(i);
            degree[i] = 0;
        }
    }

    int prunedNodes = leaves.size();

    while (prunedNodes < n)
    {
        vector<int> newLeaves;
        for (auto node : leaves)
        {
            for (auto neighbor : adjLists[node])
            {
                degree[neighbor]--;
                if (degree[neighbor] == 1)
                    newLeaves.push_back(neighbor);
            }
            degree[node] = 0;
        }
        prunedNodes += newLeaves.size();
        leaves = newLeaves;
    }

    return leaves; // center(s)
}

TreeNode *buildTree(vector<vector<int>> &adjLists, TreeNode *node, TreeNode *parent)
{
    for (auto childId : adjLists[node->id])
    {
        if (parent != nullptr && childId == parent->id)
            continue;

        auto child = new TreeNode(childId, node);
        node->children.push_back(child);
        buildTree(adjLists, child, node);
    }

    return node;
}

TreeNode *rootTree(vector<vector<int>> &adjLists, int rootId = 0)
{
    auto root = new TreeNode(rootId, nullptr);
    return buildTree(adjLists, root, nullptr);
}

string encode(TreeNode *node)
{
    if (node == nullptr)
        return "";

    vector<string> labels;

    for (auto child : node->children)
        labels.push_back(encode(child));

    sort(begin(labels), end(labels));

    string res = "";
    for (auto label : labels)
        res += label;

    return "(" + res + ")";
}

bool treesAreIsomorphic(vector<vector<int>> t1, vector<vector<int>> t2)
{
    auto tree1_centers = centerOfTree(t1);
    auto tree2_centers = centerOfTree(t2);

    auto tree1_rooted = rootTree(t1, tree1_centers[0]);
    auto tree1_encoded = encode(tree1_rooted);

    for (auto center : tree2_centers)
    {
        auto tree2_rooted = rootTree(t2, center);
        auto tree2_encoded = encode(tree2_rooted);

        if (tree1_encoded == tree2_encoded)
            return true;
    }

    return false;
}