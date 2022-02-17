#include <bits/stdc++.h>
using namespace std;

class BST
{
private:
    int data;
    BST *left, *right;

    bool isLeaf(BST *node)
    {
        if (node != nullptr && node->left == nullptr && node->right == nullptr)
            return true;

        return false;
    }

    void inOrder(BST *node, vector<int> &res)
    {
        if (node == nullptr)
            return;

        inOrder(node->left, res);
        res.push_back(node->data);
        inOrder(node->right, res);
    }

    void preOrder(BST *node, vector<int> &res)
    {
        if (node == nullptr)
            return;

        res.push_back(node->data);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }

    void postOrder(BST *node, vector<int> &res)
    {
        if (node == nullptr)
            return;

        postOrder(node->left, res);
        postOrder(node->right, res);
        res.push_back(node->data);
    }

public:
    BST() : data(0), left(nullptr), right(nullptr){};
    BST(int d) : data(d), left(nullptr), right(nullptr){};

    int height(BST *node)
    {
        if (node == nullptr)
            return 0;

        int l = height(node->left);
        int r = height(node->right);

        return max(l, r) + 1;
    }

    BST *insert(BST *node, int value)
    {
        if (node == nullptr)
            return new BST(value);

        if (value > node->data)
            node->right = insert(node->right, value);
        else
            node->left = insert(node->left, value);

        return node;
    }

    BST *inorderPredecessor(BST *node)
    {
        while (node && node->right != nullptr)
            node = node->right;

        return node;
    }

    BST *inorderSuccessor(BST *node)
    {
        while (node && node->left != nullptr)
            node = node->left;

        return node;
    }

    BST *remove(BST *node, int value)
    {
        if (node == nullptr)
            return nullptr;

        if (isLeaf(node))
        {
            delete node;
            return nullptr;
        }

        if (value < node->data)
            node->left = remove(node->left, value);
        else if (value > node->data)
            node->right = remove(node->right, value);
        else
        {
            if (height(node->left) > height(node->right))
            {
                auto q = inorderPredecessor(node->left);
                node->data = q->data;
                node->left = remove(node->left, q->data);
            }
            else
            {
                auto q = inorderSuccessor(node->right);
                node->data = q->data;
                node->right = remove(node->right, q->data);
            }
        }

        return node;
    }

    BST *search(BST *node, int value)
    {
        if (node == nullptr)
            return nullptr;

        if (node->data == value)
            return node;

        if (node->data < value)
            return search(node->right, value);

        return search(node->left, value);
    }

    BST *searchIter(BST *node, int value)
    {
        while (node != nullptr)
        {
            if (node->data == value)
                return node;

            if (node->data < value)
                node = node->right;
            else
                node = node->left;
        }

        return nullptr;
    }

    vector<int> traverse(string type, BST *root)
    {
        vector<int> res;
        if (type == "in-order")
            inOrder(root, res);
        else if (type == "pre-order")
            preOrder(root, res);
        else if (type == "post-order")
            postOrder(root, res);

        return res;
    }

    bool isBalanced(BST *node, int *height)
    {
        if (node == nullptr)
            return 1;

        int lh = 0, rh = 0;
        bool lFlag = isBalanced(node->left, &lh);
        bool rFlag = isBalanced(node->right, &rh);
        *height = max(lh, rh) + 1;

        if (abs(lh - rh) >= 2)
            return 0;
        else
            return lFlag && rFlag;
    }

} *root = NULL;
