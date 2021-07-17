#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *fast = dummy, *slow = dummy;

    int n = 0;
    while (fast->next != NULL)
    {
        fast = fast->next;
        n++;
    }

    int kNode = n - (k % n);
    for (int i = 0; i < kNode; i++)
        slow = slow->next;

    fast->next = dummy->next;
    dummy->next = slow->next;
    slow->next = NULL;

    return dummy->next;
}

int main()
{

    return 0;
}