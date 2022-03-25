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

// without memory leak
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode dummyHead(0);
    dummyHead.next = head;

    auto curr = head;
    auto prev = &dummyHead;

    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->next->val == curr->val)
        {
            int duplicate = curr->val;

            while (curr != nullptr && curr->val == duplicate)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return dummyHead.next;
}
