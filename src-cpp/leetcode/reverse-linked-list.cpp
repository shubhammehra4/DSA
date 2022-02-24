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

ListNode *reverseList(ListNode *head)
{
    ListNode *prevNode = nullptr;
    ListNode *nextNode;

    while (head != nullptr)
    {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }

    return prevNode;
}
