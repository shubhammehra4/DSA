#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    auto dummyHead = new ListNode(-1, head);
    auto prev = dummyHead;
    auto curr = dummyHead->next;

    while (curr && curr->next)
    {
        auto temp = curr->next;
        curr->next = curr->next->next;
        prev->next = temp;
        temp->next = curr;

        prev = curr;
        curr = curr->next;
    }

    return dummyHead->next;
}