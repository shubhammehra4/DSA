#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr)
        return new TreeNode(head->val);

    auto slow = head, fast = head->next;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    auto mid = slow->next;
    slow->next = nullptr;

    return new TreeNode(mid->val, sortedListToBST(head), sortedListToBST(mid->next));
}