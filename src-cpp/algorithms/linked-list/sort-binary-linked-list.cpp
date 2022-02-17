#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortBinaryList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    int zeroCnt = 0;
    int oneCnt = 0;

    auto node = head;

    while (node != nullptr)
    {
        if (node->val == 0)
            zeroCnt++;
        else
            oneCnt++;
        node = node->next;
    }

    node = head;

    while (zeroCnt--)
        node->val = 0, node = node->next;

    while (oneCnt--)
        node->val = 0, node = node->next;

    return head;
}