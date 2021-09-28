#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (!head)
        return head;

    ListNode *slow = head, *fast = head;

    // Head Start to reach the nth from beginning
    for (int i = 0; i < n; i++)
        fast = fast->next;

    if (!fast)
        return head->next;

    while (fast->next)
        fast = fast->next, slow = slow->next;

    slow->next = slow->next->next;

    return head;
}

int main()
{
    return 0;
}