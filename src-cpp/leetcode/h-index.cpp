#include <bits/stdc++.h>
using namespace std;

// heap
int hIndex(vector<int> &citations)
{
    make_heap(begin(citations), end(citations), greater<int>());

    while (!citations.empty() && citations.front() < citations.size())
    {
        pop_heap(begin(citations), end(citations), greater<int>());
        citations.pop_back();
    }

    return citations.size();
}

// priority-queue
int hIndex(vector<int> &citations)
{
    priority_queue<int, vector<int>, greater<int>> pq(begin(citations), end(citations));

    while (!pq.empty() && pq.top() < pq.size())
        pq.pop();

    return pq.size();
}

// binary-search
int hIndex(vector<int> &citations)
{
    int n = citations.size();
    sort(begin(citations), end(citations));

    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (citations[mid] < n - mid)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return n - l;
}

// linear-search 1
int hIndex(vector<int> &citations)
{
    int n = citations.size();
    sort(begin(citations), end(citations));

    int i = 0;
    while (i < n && citations[i] < (n - i))
        i++;

    return n - i;
}

// linear-search 2
int hIndex(vector<int> &citations)
{
    int n = citations.size();
    sort(begin(citations), end(citations));

    int i = 0;
    for (int i = 0; i < n; i++)
        if (i >= citations[i])
            return i;

    return n;
}