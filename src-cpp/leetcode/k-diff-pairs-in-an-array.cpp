#include <bits/stdc++.h>
using namespace std;

int findPairs(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;

    unordered_map<int, int> m;

    for (auto &n : nums)
        m[n]++;

    int cnt = 0;
    bool onlyDuplicates = k == 0;

    for (auto p : m)
    {
        if (
            (onlyDuplicates && p.second > 1) ||
            (!onlyDuplicates && m.count(p.first + k)))
        {
            ++cnt;
        }
    }

    return cnt;
}