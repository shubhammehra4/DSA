#include <bits/stdc++.h>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int d, StackNode *next) : data(d), next(next) {}
};

class Stack_List
{
private:
    StackNode *top;
    int sz;
    int currSize;

public:
    Stack_List(int sz) : top(nullptr), sz(sz), currSize(0) {}

    int size()
    {
        return currSize;
    }

    int capacity()
    {
        return sz;
    }

    bool isEmpty()
    {
        return currSize == 0;
    }

    void push(int x)
    {
        if (currSize >= sz)
            throw std::overflow_error("Stack Overflow");

        top = new StackNode(x, top);
        currSize++;
    }

    int pop()
    {
        if (currSize == 0)
            return -1;

        auto t = top;
        top = top->next;
        currSize--;
        int x = t->data;
        free(t);

        return x;
    }

    int head()
    {
        if (currSize == 0)
            return -1;

        return top->data;
    }

    vector<int> getStack()
    {
        auto curr = top;
        vector<int> stack;

        while (curr != nullptr)
        {
            stack.push_back(curr->data);
            curr = curr->next;
        }

        return stack;
    }
};

int main()
{
    Stack_List *st = new Stack_List(30);

    st->push(5);
    st->push(4);
    st->push(6);
    st->push(7);
    st->push(8);
    st->push(9);

    auto stack = st->getStack();

    for (auto s : stack)
        cout << s << " ";
    cout << endl;

    cout << st->pop() << endl;

    st->push(10);

    cout << st->head() << endl;

    return 0;
}
