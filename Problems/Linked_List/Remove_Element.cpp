#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return head;

    while (head != nullptr && head->val == val)
        head = head->next;

    ListNode *curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->next->val == val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }

    return head;
}

int main()
{
    return 0;
}