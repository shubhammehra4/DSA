#include <bits/stdc++.h>
using namespace std;

// optimised for constraints
vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
{
    vector<vector<bool>> cnt(3, vector<bool>(101, false));

    vector<int> res;
    for (auto n : nums1)
        cnt[0][n] = true;

    for (auto n : nums2)
        cnt[1][n] = true;

    for (auto n : nums3)
        cnt[2][n] = true;

    for (int i = 1; i <= 100; ++i)
        if (cnt[0][i] + cnt[1][i] + cnt[2][i] > 1)
            res.push_back(i);

    return res;
}

// simple
vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
{
    unordered_map<int, int> mp;
    vector<int> res;

    for (auto num : nums1)
        mp[num] = 1;

    for (auto num : nums2)
    {
        if (mp[num] == 1)
        {
            res.push_back(num);
            mp[num] = -1;
        }
        else if (mp[num] == 0)
            mp[num] = 2;
    }

    for (auto num : nums3)
    {
        if (mp[num] == 1 || mp[num] == 2)
        {
            res.push_back(num);
            mp[num] = -1;
        }
    }

    return res;
}