#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorder(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> s;
    auto curr = root;

    while (curr != nullptr || !s.empty())
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        res.push_back(curr->val);

        curr = curr->right;
    }

    return res;
}

vector<int> merge(vector<int> &v1, vector<int> &v2)
{
    vector<int> v3;
    int i = 0;
    int j = 0;
    int n = v1.size();
    int m = v2.size();

    while (i < n && j < m)
    {
        if (v1[i] <= v2[j])
            v3.push_back(v1[i++]);
        else
            v3.push_back(v2[j++]);
    }

    for (; i < n; i++)
        v3.push_back(v1[i]);

    for (; j < m; j++)
        v3.push_back(v2[j]);

    return v3;
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> list1 = inorder(root1);
    vector<int> list2 = inorder(root2);

    return merge(list1, list2);
}

// Alternative

void pushLeft(stack<TreeNode *> &s, TreeNode *n)
{
    while (n != nullptr)
    {
        s.push(n);
        n = n->left;
    }
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
{
    vector<int> res;
    stack<TreeNode *> s1, s2;

    pushLeft(s1, root1);
    pushLeft(s2, root2);

    while (!s1.empty() || !s2.empty())
    {

        stack<TreeNode *> &s = s1.empty()
                                   ? s2
                                   : (s2.empty()
                                          ? s1
                                      : s1.top()->val < s2.top()->val ? s1
                                                                      : s2);

        auto n = s.top();
        s.pop();

        res.push_back(n->val);
        pushLeft(s, n->right);
    }

    return res;
}