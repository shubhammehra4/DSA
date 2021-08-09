#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> ans;

void dfsPathUtil(TreeNode *root, int targetSum, vector<int> &path)
{
    if (!root)
        return;

    path.push_back(root->val);
    targetSum -= root->val;

    if (root->left == NULL && root->right == NULL)
    {
        if (targetSum == 0)
            ans.push_back(path);
    }
    else
    {
        dfsPathUtil(root->left, targetSum, path);
        dfsPathUtil(root->right, targetSum, path);
    }

    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<int> path;
    dfsPathUtil(root, targetSum, path);
    return ans;
}

int main()
{

    return 0;
}