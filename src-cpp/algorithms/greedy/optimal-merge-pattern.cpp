#include <bits/stdc++.h>
using namespace std;

int optimalMergePattern(vector<int> fileSizes)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto file : fileSizes)
        pq.push(file);

    while (pq.size() > 1)
    {
        auto size1 = pq.top();
        pq.pop();
        auto size2 = pq.top();
        pq.pop();

        pq.push(size1 + size2);
    }

    return pq.top();
}