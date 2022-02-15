#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeAndReverse(ListNode *root1, ListNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;

    ListNode *res = nullptr;
    auto a = root1;
    auto b = root2;

    while (a && b)
    {
        if (a->val <= b->val)
        {
            auto next = a->next;

            a->next = res;
            res = a;
            a = next;
        }
        else
        {
            auto next = b->next;

            b->next = res;
            res = b;
            b = next;
        }
    }

    while (a)
    {
        auto next = a->next;

        a->next = res;
        res = a;
        a = next;
    }

    while (b)
    {
        auto next = b->next;

        b->next = res;
        res = b;
        b = next;
    }

    return res;
}