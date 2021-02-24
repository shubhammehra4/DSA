#include <bits/stdc++.h>
using namespace std;

void showpq (priority_queue <int> gq)
{
    priority_queue <int> g = gq;

    while (!g.empty() )
    {
        cout << '\t' << g.top();
        g.pop();
    }

    cout << '\n';
}

void showpqmin (priority_queue <int, vector<int>, greater<int>> gq)
{
    priority_queue <int, vector<int>, greater<int>> g = gq;

    while (!g.empty() )
    {
        cout << '\t' << g.top();
        g.pop();
    }

    cout << '\n';
}

int main ()
{
    priority_queue <int> hello;
    hello.push (10);
    hello.push (30);
    hello.push (20);
    hello.push (5);
    hello.push (1);
    cout << "The priority queue hello is : ";
    showpq (hello);
    cout << "\nhello.size() : " << hello.size();
    cout << "\nhello.top() : " << hello.top();
    cout << "\nhello.pop() : ";
    hello.pop();
    showpq (hello);
    priority_queue <int, vector<int>, greater<int>> gquiz;
    gquiz.push (10);
    gquiz.push (30);
    gquiz.push (20);
    gquiz.push (5);
    gquiz.push (1);
    cout << "The priority queue gquiz is : ";
    showpqmin (gquiz);
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpqmin (gquiz);
    return 0;
}

