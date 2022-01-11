#include <bits/stdc++.h>
using namespace std;

// Starting Index of the anagrams
vector<int> findAnagrams(string s, string p)
{
    vector<int> pv(26, 0), sv(26, 0), res;

    if (s.size() < p.size())
        return {};

    for (int i = 0; i < p.size(); ++i)
    {
        ++pv[p[i] - 'a'];
        ++sv[s[i] - 'a'];
    }

    if (pv == sv)
        res.push_back(0);

    for (int i = p.size(); i < s.size(); ++i)
    {
        --sv[s[i - p.size()] - 'a'];
        ++sv[s[i] - 'a'];

        if (pv == sv)
            res.push_back(i - p.size() + 1);
    }

    return res;
}