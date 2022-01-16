#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList
{
private:
    ListNode *head;
    int size;

public:
    LinkedList() : head(NULL), size(0) {}
    LinkedList(int x) : head(new ListNode(x)), size(1) {}

    int length()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int push(int x)
    {
        auto newNode = new ListNode(x);
        size++;
        auto last = head;

        if (head == NULL)
        {
            head = newNode;
            return head->val;
        }

        while (last->next != NULL)
            last = last->next;

        last->next = newNode;
        return last->val;
    }

    void create(vector<int> a)
    {
        for (auto i : a)
            push(i);
    }

    bool insert(int idx, int x)
    {
        if (idx < 0 || idx > size)
            return false;

        auto newNode = new ListNode(x);
        size++;

        if (idx == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            auto curr = head;
            for (int i = 0; i < idx - 1; i++)
                curr = curr->next;

            newNode->next = curr->next;
            curr->next = newNode;
        }

        return true;
    }

    int remove(int idx)
    {
        ListNode *q = NULL, *p = head;

        if (idx < 0 || idx > size)
            return -1;

        int x;
        size--;
        if (idx == 0)
        {
            q = head;
            x = head->val;
            head = head->next;
            free(q);
            return x;
        }

        for (int i = 0; i < idx; i++)
            q = p, p = p->next;

        q->next = p->next;
        x = p->val;
        free(p);
        return x;
    }

    ListNode *linearSearch(int key)
    {
        ListNode *curr = head;
        while (curr != NULL)
        {
            if (key == curr->val)
                return curr;
            curr = curr->next;
        }

        return NULL;
    }

    /**
     * This Method will mutate the order of the list
     * @reason: efficiently search the same key
     */
    ListNode *dynamicSearch(int key)
    {
        ListNode *prev = NULL, *curr = head;

        while (curr != NULL)
        {
            if (key == curr->val)
            {
                prev->next = curr->next;
                curr->next = head;
                head = curr;
                return curr;
            }
            prev = curr;
            curr = curr->next;
        }

        return NULL;
    }

    void reverse()
    {
        ListNode *nextListNode, *prevListNode = NULL;
        ListNode *curr = head;

        while (curr)
        {
            nextListNode = curr->next;
            curr->next = prevListNode;
            prevListNode = curr;
            curr = nextListNode;
        }

        head = prevListNode;
    }

    vector<int> getList()
    {
        auto curr = head;
        vector<int> list;

        while (curr != nullptr)
        {
            list.push_back(curr->val);
            curr = curr->next;
        }

        return list;
    }
};

int main()
{
    LinkedList *list1 = new LinkedList();
    LinkedList *list2 = new LinkedList(2);

    vector<int> arr = {1, 2, 3, 4};
    list1->create(arr);
    cout << list1->length() << endl;

    list1->insert(2, 10);
    vector<int> l = list1->getList();
    list1->remove(1);

    cout << list1->linearSearch(3)->val << endl;
    cout << list1->dynamicSearch(3)->val << endl;
    list1->reverse();

    vector<int> l2 = list2->getList();

    return 0;
}
