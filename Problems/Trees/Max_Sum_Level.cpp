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

int maxLevelSum(TreeNode *root)
{
    if (root == nullptr)
        return -1;

    int max_sum = INT_MIN;
    int max_level = 0;

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
        int sum = 0;
        ++level;
        for (int i = q.size(); i > 0; --i)
        {
            TreeNode *n = q.front();
            q.pop();
            sum += n->val;
            if (n->left != NULL)
                q.push(n->left);
            if (n->right != NULL)
                q.push(n->right);
        }

        if (sum > max_sum)
        {
            max_sum = sum;
            max_level = level;
        }
    }

    return max_level;
}

int main()
{
    return 0;
}