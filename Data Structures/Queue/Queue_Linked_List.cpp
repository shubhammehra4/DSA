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
	Queue() : head(NULL), tail(NULL) {}

	void push(int x)
	{
		QNode *temp = new QNode(x);

		if (tail == NULL)
		{
			head = tail = temp;
			return;
		}

		tail->next = temp;
		tail = temp;
	}

	void pop()
	{
		if (head == NULL)
			return;

		QNode *temp = head;
		head = head->next;

		if (head == NULL)
			tail = NULL;

		delete (temp);
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
