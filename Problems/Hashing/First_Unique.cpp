#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    vector<int> v(26, 0);
    for (char c : s)
        v[c - 'a']++;

    for (int i = 0; i < s.size(); i++)
    {
        if (v[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

int firstUniqChar2(string s)
{
    unordered_map<char, int> m;

    for (auto i : s)
        m[i]++;

    for (int i = 0; i < s.size(); i++)
    {
        if (m[s[i]] == 1)
            return i;
    }

    return -1;
}

// Traverse string only once
int firstUniqChar3(string s)
{
    unordered_map<char, pair<int, int>> m;
    int idx = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]].first++;
        m[s[i]].second = i;
    }

    for (auto &p : m)
    {
        if (p.second.first == 1)
            idx = min(idx, p.second.second);
    }
    return idx == s.size() ? -1 : idx;
}

int main()
{
    return 0;
}