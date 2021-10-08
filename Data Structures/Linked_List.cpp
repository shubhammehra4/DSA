#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node(int x) : val(x), next(NULL) {}
};

class Linked_List
{
private:
	Node *head;
	int size;

public:
	Linked_List() : head(NULL), size(0) {}
	Linked_List(int x) : head(new Node(x)), size(1) {}

	void create(vector<int> a)
	{
		for (auto i : a)
			push(i);
	}

	int length()
	{
		return size;
	}

	void push(int x)
	{
		Node *new_node = new Node(x);
		Node *last = head;
		size++;

		if (head == NULL)
		{
			head = new_node;
			return;
		}

		while (last->next != NULL)
			last = last->next;

		last->next = new_node;
		return;
	}

	void insert(int index, int x)
	{
		if (index < 0 || index > size)
			return;

		Node *new_node = new Node(x);
		size++;

		if (index == 0)
		{
			new_node->next = head;
			head = new_node;
		}
		else
		{
			Node *curr = head;
			for (int i = 0; i < index - 1; i++)
				curr = curr->next;

			new_node->next = curr->next;
			curr->next = new_node;
		}
	}

	int remove(int idx)
	{
		Node *q = NULL, *p = head;
		int x = -1;
		if (idx < 0 || idx > size)
			return x;

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

	Node *linearSearch(int key)
	{
		Node *curr = head;
		while (curr != NULL)
		{
			if (key == curr->val)
				return curr;
			curr = curr->next;
		}

		return NULL;
	}

	// Only use if order not necessary
	Node *dynamicSearch(int key)
	{
		Node *prev = NULL, *curr = head;

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
		Node *nextNode, *prevNode = NULL;
		Node *curr = head;

		while (curr)
		{
			nextNode = curr->next;
			curr->next = prevNode;
			prevNode = curr;
			curr = nextNode;
		}

		head = prevNode;
	}

	void print()
	{
		Node *curr = head;
		while (curr != NULL)
		{
			cout << curr->val << " -> ";
			curr = curr->next;
		}
		cout << endl;
	}
};

int main()
{
	vector<int> arr = {1, 2, 3, 4};
	Linked_List *list1 = new Linked_List();
	Linked_List *list2 = new Linked_List(2);
	list1->create(arr);
	cout << list1->length() << endl;
	list1->insert(2, 10);
	list1->print();
	list1->remove(1);
	list1->print();
	list2->print();

	cout << list1->linearSearch(3)->val << endl;
	cout << list1->dynamicSearch(3)->val << endl;
	list1->print();
	list1->reverse();
	list1->print();

	return 0;
}
