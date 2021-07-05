#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Remove all duplicate values
ListNode *deleteDuplicates(ListNode *A)
{
    ListNode *origin = A;
    while (A != NULL)
    {
        while (A->next != NULL && A->val == A->next->val)
            A->next = A->next->next;

        A = A->next;
    }
    return origin;
}

// Remove All values that appear more than once
ListNode *deleteDuplicates2(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *fakeHead = new ListNode(-1);
    fakeHead->next = head;
    ListNode *pre = fakeHead;
    ListNode *cur = head;
    while (cur != NULL)
    {
        while (cur->next != NULL && cur->val == cur->next->val)
            cur = cur->next;

        if (pre->next == cur)
            pre = pre->next;
        else
            pre->next = cur->next;
        cur = cur->next;
    }
    return fakeHead->next;
}

int main()
{

    return 0;
}