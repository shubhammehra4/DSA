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

// iterator approach
using iter = vector<int>::const_iterator;
TreeNode *buildBST(iter l, iter r)
{
    if (l >= r)
        return nullptr;

    auto m = l + (r - l) / 2;

    auto node = new TreeNode(*m);
    node->left = buildBST(l, m);
    node->right = buildBST(m + 1, r);

    return node;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

    return buildBST(begin(nums), end(nums));
}

// index approach
TreeNode *helper(vector<int> &nums, int l, int r)
{
    if (l > r)
        return nullptr;

    int mid = l + (r - l) / 2;

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, l, mid - 1);
    root->right = helper(nums, mid + 1, r);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return helper(nums, 0, nums.size() - 1);
}
