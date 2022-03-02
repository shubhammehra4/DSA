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
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *cur = root;

    while (cur != nullptr)
    {
        if (p->val < cur->val && q->val < cur->val)
            cur = cur->left;
        else if (p->val > cur->val && q->val > cur->val)
            cur = cur->right;
        else
            break;
    }

    return cur;
}

// recursive
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
        return nullptr;

    if (p == root || q == root)
        return root;

    if ((p->val <= root->val && q->val > root->val) || (q->val <= root->val && p->val > root->val))
        return root;

    if (root->val > max(p->val, q->val))
        return lowestCommonAncestor(root->left, p, q);

    return lowestCommonAncestor(root->right, p, q);
}