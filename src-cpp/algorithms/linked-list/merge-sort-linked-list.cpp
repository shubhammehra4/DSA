#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *merge(ListNode *list1, ListNode *list2)
{
    auto dummyHead = new ListNode(0);
    auto ptr = dummyHead;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            ptr->next = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }

    if (list1)
        ptr->next = list1;
    else
        ptr->next = list2;

    return dummyHead->next;
}

// split into 2 lists
ListNode *getMid(ListNode *head)
{
    ListNode *midPrev = nullptr;
    while (head && head->next)
    {
        midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;

    return mid;
}

ListNode *mergeSortList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *mid = getMid(head);
    ListNode *left = mergeSortList(head);
    ListNode *right = mergeSortList(mid);
    return merge(left, right);
}
