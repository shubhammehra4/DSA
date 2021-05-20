#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *A, int B)
{
    if (A == NULL || A->next == NULL)
        return A;

    ListNode *tempHead = new ListNode(0), *last = A;
    tempHead->next = A;
    A = tempHead;
    int n = 0;

    while (last->next)
    {
        last = last->next;
        n++;
    }
    n++;

    while (n--)
    {
        if (tempHead->next->val < B)
            tempHead = tempHead->next;
        else
        {
            last->next = new ListNode(tempHead->next->val);
            last = last->next;
            tempHead->next = tempHead->next->next;
        }
    }
    return A->next;
}

int main()
{

    return 0;
}