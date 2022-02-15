#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    auto dummyHead = new ListNode(-1);
    dummyHead->next = head;

    auto curr = head;
    auto prev = dummyHead;

    while (curr != nullptr)
    {
        if (curr->next && (curr->val > curr->next->val))
        {
            while (prev->next && (prev->next->val < curr->next->val))
                prev = prev->next;

            // Swap Nodes
            auto temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;

            prev = dummyHead;
        }
        else
            curr = curr->next;
    }

    return dummyHead->next;
}
