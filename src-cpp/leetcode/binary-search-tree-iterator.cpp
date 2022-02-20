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

class BSTIterator
{
private:
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *_root)
    {
        this->populateLeftSubTree(_root);
    }

    // Push node and it's left subtree in the stack
    void populateLeftSubTree(TreeNode *node)
    {
        auto curr = node;
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
    }

    int next()
    {
        auto node = st.top();
        st.pop();

        if (node->right)
            this->populateLeftSubTree(node->right);

        return node->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};