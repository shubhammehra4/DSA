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

ListNode *middleNode(ListNode *head)
{
    auto slow = head;
    auto fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *reverseList(ListNode *head)
{
    auto p = head;
    ListNode *q = nullptr;

    while (p != nullptr)
    {
        auto on = p->next;
        p->next = q;
        q = p;
        p = on;
    }

    return q;
}

int pairSum(ListNode *head)
{
    int res = 0;
    auto mid = middleNode(head);
    auto p = head;
    auto q = reverseList(mid->next);

    mid->next = NULL;

    int res = 0;
    while (p != nullptr && q != nullptr)
    {
        res = max(res, p->val + q->val);
        p = p->next, q = q->next;
    }

    return res;
}