#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *solve(ListNode *A, int B)
{
    if (A == NULL || B == 0)
        return A;

    ListNode *current = A;
    ListNode *prev = NULL;
    int count = 0;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }

    if (B >= count)
    {
        A = A->next;
        return A;
    }
    int temp = count - B;
    current = A;
    while (temp)
    {
        prev = current;
        current = current->next;
        temp--;
    }
    prev->next = current->next;

    return A;
}

int main()
{

    return 0;
}