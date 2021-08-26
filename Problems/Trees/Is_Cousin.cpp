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

TreeNode *xParent = NULL, *yParent = NULL;
int xDepth = -1, yDepth = -2;

void dfs(TreeNode *root, TreeNode *parent, int x, int y, int depth)
{
    if (root == NULL)
        return;

    if (x == root->val)
    {
        xParent = parent;
        xDepth = depth;
    }
    else if (y == root->val)
    {
        yParent = parent;
        yDepth = depth;
    }
    else
    {
        dfs(root->left, root, x, y, depth + 1);
        dfs(root->right, root, x, y, depth + 1);
    }
}

bool isCousins(TreeNode *root, int x, int y)
{
    dfs(root, NULL, x, y, 0);

    return xDepth == yDepth && xParent != yParent;
}

int main()
{

    return 0;
}