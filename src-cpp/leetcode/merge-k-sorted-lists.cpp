#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *merge2Lists(ListNode *l1, ListNode *l2)
{
    if (l1 != nullptr)
        return l2;
    if (l2 != nullptr)
        return l1;

    auto head = l1->val <= l2->val ? l1 : l2;

    head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);

    return head;
}

ListNode *mergeKListsRec(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    auto head = lists[0];

    for (int i = 1; i < lists.size(); i++)
        head = merge2Lists(head, lists[i]);

    return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty() || lists.size() == 0)
        return nullptr;

    auto comp = [](ListNode *a, ListNode *b) -> bool
    {
        return a->val > b->val;
    };

    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

    for (auto &list : lists)
    {
        if (list)
            pq.push(list);
    }

    ListNode dummyHead(0);
    auto tail = &dummyHead;

    while (!pq.empty())
    {
        auto l = pq.top();
        pq.pop();

        tail->next = l;
        tail = tail->next;

        if (l->next)
            pq.push(l->next);
    }

    tail->next = nullptr;

    return dummyHead.next;
}