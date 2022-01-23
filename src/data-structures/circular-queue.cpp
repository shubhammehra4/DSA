#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data, Node *next = nullptr) : data(data), next(next){};
};

class MyCircularQueue
{
    Node *head;
    Node *tail;
    int maxSize;
    int size;

public:
    MyCircularQueue(int k)
    {
        maxSize = k;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        auto newNode = new Node(value);
        if (isEmpty())
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
        tail->next = head;
        size++;

        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        size--;
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return true;
        }

        auto dequeueNode = head;
        head = head->next;
        tail->next = head;
        delete dequeueNode;

        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : head->data;
    }

    int Rear()
    {
        return isEmpty() ? -1 : tail->data;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */