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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    auto node = head;
    while (node->next)
    {
        if (node->val == node->next->val)
        {
            auto del = node->next;
            node->next = node->next->next;
            delete (del);
        }
        else
            node = node->next;
    }

    return head;
}

// alter
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    auto prev = new ListNode(-101, head);
    auto curr = prev->next;
    auto res = prev;

    while (curr)
    {
        if (curr->val == prev->val)
        {
            auto del = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete (del);
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }

    return res->next;
}
