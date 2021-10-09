#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

    ListNode *fakeHead = new ListNode(-1, head);
    ListNode *prev = fakeHead;

    while (head)
    {
        while (head->next && head->val == head->next->val)
            head = head->next;

        if (prev->next == head)
            prev = prev->next;
        else
            prev->next = head->next;

        head = head->next;
    }
    return fakeHead->next;
}

int main()
{

    return 0;
}