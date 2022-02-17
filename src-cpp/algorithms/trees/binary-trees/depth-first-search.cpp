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

vector<int> depthFirstSearch(TreeNode *root)
{
    if (root == nullptr)
        return {};

    stack<TreeNode *> st;

    vector<int> res;
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

void depthFirstSearchRec(TreeNode *root, vector<int> &res)
{
    if (root == nullptr)
        return;

    depthFirstSearch(root->left);
    res.push_back(root->val);
    depthFirstSearch(root->right);
}