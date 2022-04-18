#include <bits/stdc++.h>
using namespace std;

bool canReorderDoubled(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int a : arr)
        freq[a]++;

    vector<int> keys;
    for (auto it : freq)
        keys.push_back(it.first);

    sort(begin(keys), end(keys), [](int i, int j)
         { return abs(i) < abs(j); });

    for (int x : keys)
    {
        if (freq[x] > freq[2 * x])
            return false;

        freq[2 * x] -= freq[x];
    }

    return true;
}