#include <bits/stdc++.h>
using namespace std;

// Alternative : Count Sort
string frequencySort(string s)
{
    priority_queue<pair<int, char>> pq;
    unordered_map<char, int> m;
    string str = "";

    for (auto c : s)
        m[c]++;

    for (auto it : m)
        pq.push({it.second, it.first});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        str.insert(str.length(), top.first, top.second);
    }

    return str;
}

int main()
{
    return 0;
}