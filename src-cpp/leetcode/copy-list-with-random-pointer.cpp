#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// space optimised
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;

    auto iter = head;
    Node *next;
    Node *copy;

    while (iter != nullptr) // link copies of node side-by-side
    {
        next = iter->next;

        copy = new Node(iter->val);
        iter->next = copy;
        copy->next = next;

        iter = next;
    }

    iter = head;
    while (iter != nullptr)
    {
        if (iter->random != nullptr)
            iter->next->random = iter->random->next;

        iter = iter->next->next; // even number of nodes so this will not throw error
    }

    iter = head;
    auto dummyHead = new Node(-1);
    auto copyIter = dummyHead;

    while (iter != nullptr)
    {
        next = iter->next->next;
        copy = iter->next;

        copyIter->next = copy;
        copyIter = copy;

        iter->next = next;

        iter = next;
    }

    return dummyHead->next;
}

// using hashmap
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;

    auto dummyHead = new Node(-1);
    unordered_map<Node *, Node *> mp;

    auto node = head;
    auto copyNode = dummyHead;

    while (node != nullptr)
    {
        auto t = new Node(node->val);

        copyNode->next = t;
        mp[node] = t;

        copyNode = copyNode->next;
        node = node->next;
    }

    node = head;
    copyNode = dummyHead->next;

    while (node != nullptr)
    {
        if (node->random != nullptr)
            copyNode->random = mp[node->random];

        copyNode = copyNode->next;
        node = node->next;
    }

    return dummyHead->next;
}