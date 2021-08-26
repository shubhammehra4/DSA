#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeBarcodes(vector<int> &b)
{
    unordered_map<int, int> m;
    set<pair<int, int>> s;

    for (auto n : b)
        ++m[n];

    for (auto it = begin(m); it != end(m); ++it)
        s.insert({it->second, it->first});

    int pos = 0;
    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2)
        {
            if (pos >= b.size())
                pos = 1;
            b[pos] = it->second;
        }
    }
    return b;
}

int main()
{

    return 0;
}