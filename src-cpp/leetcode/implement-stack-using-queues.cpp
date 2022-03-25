#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    queue<int> q1;

public:
    MyStack() {}

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        int len = q1.size();
        for (int i = 0; i < len - 1; i++)
        {
            int tmp = q1.front();
            q1.pop();
            q1.push(tmp);
        }

        int res = q1.front();
        q1.pop();

        return res;
    }

    /** Get the top element. */
    int top()
    {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */