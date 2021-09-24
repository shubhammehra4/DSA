#include <bits/stdc++.h>
using namespace std;

class BrowserHistory
{
public:
    vector<string> history;
    int pos = 0;
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
    }

    void visit(string url)
    {
        ++pos;
        history.resize(pos);
        history.push_back(url);
    }

    string back(int steps)
    {
        pos = max(0, pos - steps);
        return history[pos];
    }

    string forward(int steps)
    {
        pos = min((int)history.size() - 1, pos + steps);
        return history[pos];
    }
};

// Stack

class BrowserHistory2
{
public:
    stack<string> h_back, h_forward;
    string cur;
    BrowserHistory2(string homepage) { cur = homepage; }
    void visit(string url)
    {
        h_forward = stack<string>();
        h_back.push(cur);
        cur = url;
    }
    string back(int steps)
    {
        while (--steps >= 0 && !h_back.empty())
        {
            h_forward.push(cur);
            cur = h_back.top();
            h_back.pop();
        }
        return cur;
    }
    string forward(int steps)
    {
        while (--steps >= 0 && !h_forward.empty())
        {
            h_back.push(cur);
            cur = h_forward.top();
            h_forward.pop();
        }
        return cur;
    }
};

int main()
{
    return 0;
}