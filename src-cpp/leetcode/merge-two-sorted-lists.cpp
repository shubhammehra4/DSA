#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *root1, ListNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;

    ListNode *res = new ListNode(-1);

    auto head = res;
    auto a = root1;
    auto b = root2;

    while (a && b)
    {
        if (a->val <= b->val)
        {
            res->next = a;
            a = a->next;
            res = res->next;
        }
        else
        {
            res->next = b;
            b = b->next;
            res = res->next;
        }
    }

    if (a != nullptr)
        res->next = a;

    if (b != nullptr)
        res->next = b;

    // alter
    // while (a)
    // {
    //     res->next = a;
    //     a = a->next;
    //     res = res->next;
    // }

    // while (b)
    // {
    //     res->next = b;
    //     b = b->next;
    //     res = res->next;
    // }

    return head->next;
}