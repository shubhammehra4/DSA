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
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;

    while (root || !st.empty())
    {
        if (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }

    return res;
}

// recursive
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;

    function<void(TreeNode *)> inorderUtil = [&inorderUtil, &res](TreeNode *node) -> void
    {
        if (node == nullptr)
            return;

        inorderUtil(node->left);
        res.push_back(node->val);
        inorderUtil(node->right);
    };

    inorderUtil(root);

    return res;
}