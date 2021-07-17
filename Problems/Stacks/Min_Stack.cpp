#include <bits/stdc++.h>
using namespace std;

stack<int> elms;
stack<int> min_info;
class MinStack
{
private:
public:
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

MinStack::MinStack()
{
    elms = {};
    min_info = {};
}

void MinStack::push(int x)
{
    elms.push(x);
    if (min_info.empty())
        min_info.push(x);
    else
    {
        int to_push = min(min_info.top(), x);
        min_info.push(to_push);
    }
}

void MinStack::pop()
{
    if (elms.empty())
        return;
    elms.pop();
    min_info.pop();
}

int MinStack::top()
{
    if (elms.size() == 0)
        return -1;
    return elms.top();
}

int MinStack::getMin()
{
    if (min_info.size() == 0)
        return -1;
    return min_info.top();
}

void PrintStack(stack<int> s)
{
    if (s.empty())
        return;

    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}
int main()
{
    MinStack min;
    min.push(3);
    min.push(1);
    min.push(10);
    min.pop();
    min.pop();
    PrintStack(elms);
    cout << endl;
    PrintStack(min_info);

    return 0;
}