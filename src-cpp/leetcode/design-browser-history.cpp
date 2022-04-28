#include <bits/stdc++.h>
using namespace std;

// vector as list
class BrowserHistory
{
    vector<string> history;
    int pos;

public:
    BrowserHistory(string homepage)
    {
        pos = 0;
        history.push_back(homepage);
    }

    void visit(string url)
    {
        pos += 1;
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
        pos = min((int)size(history) - 1, pos + steps);
        return history[pos];
    }
};

// stack
class BrowserHistory
{
    stack<string> history;
    stack<string> future;

public:
    BrowserHistory(string homepage) { history.push(homepage); }

    void visit(string url)
    {
        history.push(url);
        future = stack<string>(); // reset the forward stack.
    }

    string back(int steps)
    {
        while (steps > 0 && history.size() > 1)
        {
            future.push(history.top());
            history.pop();
            steps--;
        }

        return history.top();
    }

    string forward(int steps)
    {
        while (steps > 0 && future.size() > 0)
        {
            history.push(future.top());
            future.pop();
            steps--;
        }
        return history.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */