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

// iterative-2
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;

    while (root || !st.empty())
    {
        if (root != nullptr)
        {
            if (root->right != nullptr)
                st.push(root->right);

            res.push_back(root->val);

            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();
        }
    }

    return res;
}

// iterative - 1
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;

    if (root == nullptr)
        return res;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        auto node = st.top();
        st.pop();
        res.push_back(node->val);

        if (node->right != nullptr)
            st.push(node->right);
        if (node->left != nullptr)
            st.push(node->left);
    }

    return res;
}

// recursive
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;

    function<void(TreeNode *)> preorderUtil = [&preorderUtil, &res](TreeNode *node) -> void
    {
        if (node == nullptr)
            return;

        res.push_back(node->val);
        preorderUtil(node->left);
        preorderUtil(node->right);
    };

    preorderUtil(root);

    return res;
}