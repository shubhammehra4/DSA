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

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr)
        return root2;

    if (root2 == nullptr)
        return root1;

    root1->val = root1->val + root2->val;

    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr)
        return root2;

    if (root2 == nullptr)
        return root1;

    stack<pair<TreeNode *, TreeNode *>> st;
    st.push({root1, root2});

    while (!st.empty())
    {
        auto &nodes = st.top();
        st.pop();

        auto r1 = nodes.first;
        auto r2 = nodes.second;

        if (r2 != nullptr)
        {
            r1->val = r1->val + r2->val;

            if (r1->left == nullptr)
                r1->left = r2->left;
            else
                st.push({r1->left, r2->left});

            if (r1->right == nullptr)
                r1->right = r2->right;
            else
                st.push({r1->right, r2->right});
        }
    }

    return root1;
}

// create a copy
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;

    auto r1 = root1 ? root1 : nullptr;
    auto r2 = root2 ? root2 : nullptr;

    auto root = new TreeNode(r1->val + r2->val);

    root->left = mergeTrees(r1 ? r1->left : nullptr, r2 ? r2->left : nullptr);
    root->right = mergeTrees(r1 ? r1->right : nullptr, r2 ? r2->right : nullptr);

    return root;
}