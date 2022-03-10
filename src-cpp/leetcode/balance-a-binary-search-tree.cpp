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

TreeNode *balanceBST(TreeNode *root)
{
    function<vector<TreeNode *>(TreeNode *)> inorderUtil =
        [](TreeNode *root) -> vector<TreeNode *>
    {
        vector<TreeNode *> res;
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
                // storing nodes instead of values as it's expensive to create new nodes
                res.push_back(root);
                root = root->right;
            }
        }

        return res;
    };

    auto inorderArr = inorderUtil(root);

    function<TreeNode *(int, int)> sortedArrToBST = [&inorderArr, &sortedArrToBST](int start, int end) -> TreeNode *
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode *root = inorderArr[mid];
        root->left = sortedArrToBST(start, mid - 1);
        root->right = sortedArrToBST(mid + 1, end);

        return root;
    };

    return sortedArrToBST(0, inorderArr.size() - 1);
}

// alter
vector<TreeNode *> sortedArr;
TreeNode *balanceBST(TreeNode *root)
{
    inorderTraverse(root);
    return sortedArrayToBST(0, sortedArr.size() - 1);
}

void inorderTraverse(TreeNode *root)
{
    if (root == NULL)
        return;

    inorderTraverse(root->left);
    sortedArr.push_back(root);
    inorderTraverse(root->right);
}

TreeNode *sortedArrayToBST(int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    TreeNode *root = sortedArr[mid];
    root->left = sortedArrayToBST(start, mid - 1);
    root->right = sortedArrayToBST(mid + 1, end);

    return root;
}