#include <bits/stdc++.h>
using namespace std;

// map
int numIdenticalPairs(vector<int> &nums)
{
    int cnt = 0;
    unordered_map<int, int> count;
    for (auto num : nums)
        cnt += count[num]++;

    return cnt;
}

// map (nc2)
int numIdenticalPairs(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int cnt = 0;
    for (auto num : nums)
        mp[num]++;

    for (auto p : mp)
        cnt += p.second * (p.second - 1) / 2; // choose 2 out of n

    return cnt;
}

// brute-force
int numIdenticalPairs(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (nums[i] == nums[j])
                cnt++;
    }

    return cnt;
}