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

ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return head;

    while (head != nullptr && head->val == val)
        head = head->next;

    auto curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->next->val == val)
        {
            auto del = curr->next;
            curr->next = curr->next->next;
            delete del;
        }
        else
            curr = curr->next;
    }

    return head;
}

// alter
ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return head;

    auto prevNode = new ListNode(-1, head);
    auto res = prevNode;
    auto node = prevNode->next;

    while (node != nullptr)
    {
        if (node->val == val)
        {
            auto del = node;
            prevNode->next = node->next;
            node = node->next;
            delete del;
        }
        else
        {
            prevNode = prevNode->next;
            node = node->next;
        }
    }

    return res->next;
}
