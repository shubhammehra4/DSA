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

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;

    modifiedHeight(root, diameter);

    return diameter;
}

int modifiedHeight(TreeNode *node, int &diameter)
{
    if (!node)
        return 0;

    int l = modifiedHeight(node->left, diameter);
    int r = modifiedHeight(node->right, diameter);
    diameter = max(diameter, l + r);

    return max(l, r) + 1;
}

int main()
{

    return 0;
}