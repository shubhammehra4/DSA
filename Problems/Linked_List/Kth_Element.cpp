#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int solve(ListNode *A, int B)
{
    if (A == NULL || A->next == NULL)
        return -1;

    ListNode *temp = A;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    int reqNode = ((n / 2 + 1) - B);

    if (reqNode <= 0)
        return -1;

    struct ListNode *current = A;
    int count = 1;
    while (current != NULL)
    {
        if (count == reqNode)
            return (current->val);
        count++;
        current = current->next;
    }
}

int main()
{

    return 0;
}