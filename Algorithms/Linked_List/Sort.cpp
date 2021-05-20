#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef ListNode *ln;

ListNode *sortBinary(ListNode *A)
{
    ln zero = new ListNode(0), one = new ListNode(1);
    ln head1 = zero, head2 = one;
    while (A)
    {
        if (A->val == 0)
        {
            zero->next = A;
            zero = zero->next;
        }
        else
        {
            one->next = A;
            one = one->next;
        }
        A = A->next;
    }
    zero->next = head2->next;
    one->next = NULL;
    return head1->next;
}

int main()
{

    return 0;
}