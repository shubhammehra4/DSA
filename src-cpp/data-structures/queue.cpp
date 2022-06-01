#include <bits/stdc++.h>
using namespace std;

struct QNode
{
    int data;
    QNode *next;
    QNode(int d) : data(d), next(NULL) {}
};

class Queue
{
private:
    QNode *head, *tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    bool isEmpty()
    {
        return tail == nullptr;
    }

    int push(int x)
    {
        auto newNode = new QNode(x);
        if (tail == nullptr)
        {
            head = tail = newNode;
            return tail->data;
        }

        tail->next = newNode;
        tail = newNode;

        return tail->data;
    }

    int pop()
    {
        if (head == nullptr)
            return -1;

        auto hd = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;

        int data = hd->data;
        delete (hd);
        return data;
    }

    int front()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }

    int back()
    {
        if (tail == NULL)
            return -1;
        return tail->data;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.pop();
    q.pop();
    q.push(30);
    q.push(40);
    q.push(50);
    q.pop();
    cout << "Queue Front : " << q.front() << endl;
    cout << "Queue Rear : " << q.back();
}
