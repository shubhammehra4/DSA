#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *n;
    while (curr != NULL)
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}
int lPalin(ListNode *A)
{
    ListNode *slow = A, *fast = A;

    if (A == NULL || A->next == NULL)
        return 1;
    if (A->next->next == NULL)
    {
        if (A->val == A->next->val)
            return 1; //if num of nodes are 2 checking palindrom or not
        else
            return 0;
    }

    while (fast->next != NULL && fast->next->next != NULL) //finding middile node of linkedlist
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *revA = reverse(slow->next); //reversing linked list after midpoint
    while (A != NULL && revA != NULL)
    {
        if (A->val != revA->val)
            return 0;
        A = A->next;
        revA = revA->next;
    }
    return 1;
}

int main()
{

    return 0;
}