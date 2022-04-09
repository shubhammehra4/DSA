#include <bits/stdc++.h>
using namespace std;

// multi-set
int lastStoneWeight(vector<int> &stones)
{
    multiset<int> s(begin(stones), end(stones));

    while (s.size() > 1)
    {
        auto stone1 = *prev(end(s));
        s.erase(prev(end(s)));
        auto stone2 = *prev(end(s));
        s.erase(prev(end(s)));

        if (stone1 - stone2 > 0)
            s.insert(stone1 - stone2);
    }

    return s.empty() ? 0 : *s.begin();
}

// priority-queue
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq(begin(stones), end(stones));

    while (pq.size() > 1)
    {
        auto stone1 = pq.top();
        pq.pop();
        auto stone2 = pq.top();
        pq.pop();

        if (stone1 != stone2)
            pq.push(stone1 - stone2);
    }

    return pq.empty() ? 0 : pq.top();
}