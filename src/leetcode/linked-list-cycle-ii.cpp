#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;

    auto fast = head->next->next;
    auto slow = head->next;

    while (fast && fast->next && fast != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (!fast || !fast->next)
        return nullptr;

    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

// Hash Map
ListNode *detectCycleH(ListNode *head)
{
    unordered_set<ListNode *> s;
    auto curr = head;
    while (!curr)
    {
        if (s.find(curr) != s.end())
            return curr;
        else
            s.insert(curr);
        curr = curr->next;
    }

    return nullptr;
}
