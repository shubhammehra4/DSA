/*
Given a binary tree where node values are digits from 1 to 9. 
A path in the binary tree is said to be pseudo-palindromic if at least 
one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the 
root node to leaf nodes.
*/
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

void dfsUtil(TreeNode *root, int &check, int &palinCnt)
{
    if (root == NULL)
        return;

    check = (check ^ (1 << root->val));

    if (root->left == NULL && root->right == NULL)
    {
        int cnt = 0, dup = check;
        while (dup > 0)
        {
            dup = (dup & (dup - 1));
            cnt++;
        }
        if (cnt <= 1)
            palinCnt++;
    }

    dfsUtil(root->left, check, palinCnt);
    dfsUtil(root->right, check, palinCnt);

    check = (check ^ (1 << root->val));
}

int pseudoPalindromicPaths(TreeNode *root)
{
    int palinCnt = 0;
    /* 
    The catch is 1 <= node.val <= 9
    Instead of using a vector or unordered_map we can use a number
    
    For every visited node, toggle the bit position in the integer. 
    If you reach a leaf node and count of set bits is greater than one, 
    there's no way you can form a palindrome. 
    */
    int check = 0;
    dfsUtil(root, check, palinCnt);

    return palinCnt;
}

int main()
{
    return 0;
}