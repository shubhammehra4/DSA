#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int> &changed)
{
    if (changed.size() % 2)
        return {};

    unordered_map<int, int> mp;
    for (auto a : changed)
        mp[a]++;

    vector<int> keys;
    for (auto it : mp)
        keys.push_back(it.first);

    sort(keys.begin(), keys.end(), [](int i, int j)
         { return abs(i) < abs(j); });

    vector<int> res;
    for (int x : keys)
    {
        if (mp[x] > mp[2 * x])
            return {};

        for (int i = 0; i < mp[x]; ++i, mp[2 * x]--)
            res.push_back(x);
    }

    return res;
}