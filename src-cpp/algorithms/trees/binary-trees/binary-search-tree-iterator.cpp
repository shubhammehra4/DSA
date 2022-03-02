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
    stack<TreeNode *> s;
    TreeNode *node;
    bool forward;

public:
    BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward){};

    bool hasNext()
    {
        return node != nullptr || !s.empty();
    }

    int next()
    {
        while (node || !s.empty())
        {
            if (node)
            {
                s.push(node);
                node = forward ? node->left : node->right;
            }
            else
            {
                node = s.top();
                s.pop();
                int nextVal = node->val;
                node = forward ? node->right : node->left;
                return nextVal;
            }
        }

        return -1;
    }
};

// alter
class BSTIterator
{
    stack<TreeNode *> st;
    bool forward;

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

    // Push node and it's right subtree in the stack
    void populateRightSubTree(TreeNode *node)
    {
        auto curr = node;
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->right;
        }
    }

public:
    BSTIterator(TreeNode *_root, bool _forward = true)
    {
        this->forward = _forward;

        if (_forward)
            this->populateLeftSubTree(_root);
        else
            this->populateRightSubTree(_root);
    }

    bool hasNext()
    {
        return !st.empty();
    }

    int next()
    {
        auto node = st.top();
        st.pop();

        if (node->right != nullptr)
        {
            if (this->forward)
                this->populateLeftSubTree(node->right);
            else
                this->populateRightSubTree(node->left);
        }

        return node->val;
    }
};

// alter
// operator overloading
class BSTIterator
{
    stack<TreeNode *> s;
    TreeNode *node;
    bool forward;
    int cur;

public:
    BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) { (*this)++; };

    int operator*() { return cur; }

    void operator++(int)
    {
        while (node || !s.empty())
        {
            if (node)
            {
                s.push(node);
                node = forward ? node->left : node->right;
            }
            else
            {
                node = s.top();
                s.pop();
                cur = node->val;
                node = forward ? node->right : node->left;
                break;
            }
        }
    }
};