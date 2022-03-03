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

ListNode *reverseGroup(ListNode *first, ListNode *last)
{
    auto prev = last;

    while (first != last)
    {
        auto nextNode = first->next;
        first->next = prev;
        prev = first;
        first = nextNode;
    }

    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    auto node = head;

    for (int i = 0; i < k; ++i)
    {
        if (node == nullptr)
            return head;

        node = node->next;
    }

    auto newHead = reverseGroup(head, node);
    head->next = reverseKGroup(node, k);

    return newHead;
}