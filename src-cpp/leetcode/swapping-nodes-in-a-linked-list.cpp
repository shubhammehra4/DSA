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

ListNode *swapNodes(ListNode *head, int k)
{
    auto node1 = head;
    for (int i = 1; i < k; i++)
        node1 = node1->next;

    ListNode *node2 = head, *end = node1->next;
    while (end)
    {
        end = end->next;
        node2 = node2->next;
    }

    swap(node2->val, node1->val); // in this case swapping values works
    return head;
}