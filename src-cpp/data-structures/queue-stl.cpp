#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }

    cout << '\n';
}

int main()
{
    queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);
    cout << "The queue gquiz is : ";
    printQueue(gquiz);
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    printQueue(gquiz);
    return 0;
}
