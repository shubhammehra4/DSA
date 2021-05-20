#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *A)
{
    if (A == NULL || A->next == NULL)
        return A;

    ListNode *start = new ListNode(0);
    ListNode *head = A;
    start->next = head;
    ListNode *i = head, *prev = start;

    while (i != NULL)
    {
        if (i->next && (i->val > i->next->val))
        {
            while (prev->next && (prev->next->val < i->next->val))
                prev = prev->next;

            ListNode *temp = prev->next;
            prev->next = i->next;
            i->next = i->next->next;
            prev->next->next = temp;
            prev = start;
        }
        else
            i = i->next;
    }

    return start->next;
}

int main()
{

    return 0;
}