#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
    stack<int> in;
    stack<int> out;

public:
    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        auto p = peek();
        out.pop();
        return p;
    }

    int peek()
    {
        if (out.empty())
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }

        return out.top();
    }

    bool empty()
    {
        return in.empty() && out.empty();
    }
};
