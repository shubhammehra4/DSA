#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *A, ListNode *B)
{
    if (!A)
        return B;
    if (!B)
        return A;

    int carry = (A->val + B->val) / 10;
    ListNode *res = new ListNode((A->val + B->val) % 10);
    ListNode *tail = res;
    A = A->next;
    B = B->next;

    while (A || B || carry)
    {
        int sum = ((A ? A->val : 0) + (B ? B->val : 0) + carry);
        ListNode *t = new ListNode(sum % 10);
        carry = sum / 10;

        if (A)
            A = A->next;
        if (B)
            B = B->next;
        tail->next = t;
        tail = t;
    }

    return res;
}

// Cannot Handle Large Numbers
ListNode *addTwoNumbers1(ListNode *A, ListNode *B)
{
    int n = 0, m = 0;
    int i = 0;
    ListNode *current = A;
    while (current != NULL)
    {
        n += current->val * pow(10, i);
        i++;
        current = current->next;
    }
    current = B;
    i = 0;
    while (current != NULL)
    {
        m += current->val * pow(10, i);
        i++;
        current = current->next;
    }
    int res = n + m;
    int temp;
    ListNode *ans = new ListNode(0);
    ListNode *head = ans;

    while (res > 0)
    {
        head->next = new ListNode(res % 10);
        res = res / 10;
        head = head->next;
    }

    return ans->next;
}
int main()
{

    return 0;
}