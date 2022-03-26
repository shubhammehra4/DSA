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

ListNode *mergeNodes(ListNode *head)
{
    ListNode dummy, *tail = &dummy;

    while (head != nullptr)
    {
        if (head->val == 0)
            head = head->next;

        if (head == nullptr)
            break;

        int sum = 0;
        while (head->val != 0)
        {
            sum += head->val;
            head = head->next;
        }

        tail->next = new ListNode(sum);
        tail = tail->next;
    }

    return dummy.next;
}
