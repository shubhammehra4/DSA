#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> m;

public:
    void set(string key, string value, int timestamp)
    {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = upper_bound(begin(m[key]), end(m[key]), pair<int, string>(timestamp, ""), [](const pair<int, string> &a, const pair<int, string> &b)
                              { return a.first < b.first; }); // upper bound because we need the latest value

        return it == begin(m[key]) ? "" : prev(it)->second;
    }
};
