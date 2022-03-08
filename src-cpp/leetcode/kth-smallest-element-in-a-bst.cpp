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

int kthSmallest(TreeNode *root, int k)
{
    int nodeCnt = 0;
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
            nodeCnt++;

            if (nodeCnt == k)
                return root->val;

            root = root->right;
        }
    }

    return -1;
}

int kthSmallest(TreeNode *root, int k)
{
    vector<int> inorder;
    stack<TreeNode *> st;

    while (root || !st.empty() || inorder.size() < k)
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
            inorder.push_back(root->val);
            root = root->right;
        }
    }

    return inorder[k - 1];
}
