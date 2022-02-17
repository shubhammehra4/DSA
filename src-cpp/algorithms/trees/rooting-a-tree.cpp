#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int id;
    TreeNode *parent;
    vector<TreeNode *> children;
    TreeNode(int _id, TreeNode *_parent) : id(_id), parent(_parent), children(vector<TreeNode *>()) {}
};

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

// For a Balanced Tree select the rootId as the center of the tree
TreeNode *rootTree(vector<vector<int>> &adjLists, int rootId = 0)
{
    auto root = new TreeNode(rootId, nullptr);
    return buildTree(adjLists, root, nullptr);
}
