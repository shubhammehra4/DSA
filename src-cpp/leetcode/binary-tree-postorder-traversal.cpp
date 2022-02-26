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
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;

    while (root || !st.empty())
    {
        if (root != nullptr)
        {
            if (root->left != nullptr)
                st.push(root->left);

            res.push_back(root->val);

            root = root->right;
        }
        else
        {
            root = st.top();
            st.pop();
        }
    }

    reverse(begin(res), end(res));

    return res;
}

// recursive
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;

    function<void(TreeNode *)> postorderUtil = [&postorderUtil, &res](TreeNode *node) -> void
    {
        if (node == nullptr)
            return;

        postorderUtil(node->left);
        postorderUtil(node->right);
        res.push_back(node->val);
    };

    postorderUtil(root);

    return res;
}