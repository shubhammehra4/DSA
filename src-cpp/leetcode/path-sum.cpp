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
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;

    queue<pair<TreeNode *, int>> q;
    q.push({root, targetSum});

    while (!q.empty())
    {
        auto node = q.front().first;
        auto sum = q.front().second;
        q.pop();

        if (node->left == nullptr && node->right == nullptr && sum == node->val)
            return true;

        if (node->left != nullptr)
            q.push({node->left, sum - node->val});

        if (node->right != nullptr)
            q.push({node->right, sum - node->val});
    }

    return false;
}

// iterative - stack
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;

    stack<pair<TreeNode *, int>> st;
    st.push({root, targetSum});

    while (!st.empty())
    {
        auto node = st.top().first;
        auto sum = st.top().second;
        st.pop();

        if (node->left == nullptr && node->right == nullptr && sum == node->val)
            return true;

        if (node->right != nullptr)
            st.push({node->right, sum - node->val});

        if (node->left != nullptr)
            st.push({node->left, sum - node->val});
    }

    return false;
}

// recursive
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
        return false;

    if (root->left == nullptr && root->right == nullptr && targetSum == root->val)
        return true;

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}