#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Stack_List
{
private:
	Node *top;
	int size;
	int curr_size;

public:
	Stack_List(int s)
	{
		top = NULL;
		size = s;
		curr_size = 0;
	}

	void push(int x)
	{
		if (curr_size >= size)
		{

			cout << "Stack Overflow\n";
			return;
		}

		Node *t = new Node;
		t->data = x;
		t->next = top;
		curr_size++;
		top = t;
	}

	int pop()
	{
		Node *t;
		int x = -1;
		if (curr_size == 0)
		{
			cout << "Stack is Empty\n";
			return x;
		}

		t = top;
		top = top->next;
		x = t->data;
		curr_size--;
		free(t);

		return x;
	}

	int getTop()
	{
		if (curr_size == 0)
		{
			cout << "Stack is Empty\n";
			return -1;
		}

		return top->data;
	}

	void print()
	{
		Node *p;
		p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};

int main()
{
	Stack_List *st = new Stack_List(5);

	st->push(5);
	st->push(4);

	st->print();

	cout << st->pop() << endl;

	st->push(6);
	st->push(7);
	st->push(8);
	st->push(9);
	st->push(10);

	st->print();
	cout << st->pop() << endl;

	return 0;
}
