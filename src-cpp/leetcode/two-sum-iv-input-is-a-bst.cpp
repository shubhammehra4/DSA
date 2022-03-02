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

        return -1; // never reach & not necessary
    }
};

// T - O(n), S - O(logn)
// using iterator
bool findTarget(TreeNode *root, int k)
{
    if (root == nullptr)
        return false;

    BSTIterator l(root, true);
    BSTIterator r(root, false);

    auto i = l.next();
    auto j = r.next();

    while (i < j)
    {
        int sum = i + j;

        if (sum == k)
            return true;

        if (sum < k)
            i = l.next();
        else
            j = r.next();
    }

    return false;
}

// T - O(n), S - O(n)
// inorder traversal
bool findTarget(TreeNode *root, int k)
{
    if (root == nullptr)
        return false;

    vector<int> nums;
    function<void(TreeNode *)> inorder = [&nums, &inorder](TreeNode *node) -> void
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        nums.push_back(node->val);
        inorder(node->right);
    };

    inorder(root);

    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        int sum = nums[i] + nums[j];
        if (sum == k)
            return true;

        if (sum < k)
            i++;
        else
            j--;
    }

    return false;
}

// T - O(nlogn), S - O(n)
// searching each value
bool findTarget(TreeNode *root, int k)
{
    if (root == nullptr)
        return false;

    auto searchBST = [](TreeNode *root, int val) -> TreeNode *
    {
        while (root != nullptr && root->val != val)
        {
            root = (root->val > val) ? root->left : root->right;
        }

        return root;
    };

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        auto targetNode = searchBST(root, k - node->val);

        if (targetNode != nullptr && targetNode != node)
            return true;

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);
    }

    return false;
}
