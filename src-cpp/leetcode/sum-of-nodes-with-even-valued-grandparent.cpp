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

int sumEvenGrandparent(TreeNode *root, int parent = 1, int grandParent = 1)
{
    if (root == nullptr)
        return 0;

    auto left = sumEvenGrandparent(root->left, root->val, parent);
    auto right = sumEvenGrandparent(root->right, root->val, parent);

    return left + right + (grandParent % 2 ? 0 : root->val);
}

// brute-force
int sumEvenGrandparent(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int sum = 0;

    function<void(TreeNode *)> dfs = [&sum, &dfs](TreeNode *node) -> void
    {
        if (node == nullptr)
            return;

        auto leftNode = node->left;
        auto rightNode = node->right;

        if (node->val % 2 == 0)
        {
            if (leftNode)
            {
                if (leftNode->left)
                    sum += leftNode->left->val;

                if (leftNode->right)
                    sum += leftNode->right->val;
            }

            if (rightNode)
            {
                if (rightNode->left)
                    sum += rightNode->left->val;

                if (rightNode->right)
                    sum += rightNode->right->val;
            }
        }

        dfs(leftNode);
        dfs(rightNode);
    };

    dfs(root);

    return sum;
}
