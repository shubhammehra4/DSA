#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
        return head;

    int n = 1;
    auto tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
        n++;
    }

    tail->next = head; // circular
    int newHeadIdx = n - k % n;

    while (newHeadIdx--)
        tail = tail->next;

    head = tail->next;
    tail->next = NULL;
    return head;
}

// alter
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
        return head;

    int n = 0;
    auto node = head;
    while (node != nullptr)
        node = node->next, n++;

    k %= n;
    if (k == 0)
        return head;

    int m = n - k - 1;

    auto pivotNode = head;
    while (m--)
        pivotNode = pivotNode->next;

    auto newHead = pivotNode->next;
    pivotNode->next = nullptr;

    node = newHead;
    while (node->next)
        node = node->next;

    node->next = head;

    return newHead;
}