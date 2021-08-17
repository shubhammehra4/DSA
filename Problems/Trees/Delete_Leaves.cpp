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

void postorder(TreeNode *&root, int target)
{
    if (root == NULL)
        return;

    postorder(root->left, target);
    postorder(root->right, target);
    if (root->val == target && root->left == NULL && root->right == NULL)
        root = NULL;
}

TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    postorder(root, target);
    return root;
}

int main()
{

    return 0;
}