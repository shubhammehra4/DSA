#include <bits/stdc++.h>
using namespace std;

// Boyer-Moore Voting Algorithm
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int candidate = -1;

    for (auto num : nums)
    {
        if (count == 0)
            candidate = num;

        count += num == candidate ? 1 : -1;
    }

    return candidate;
}

// Alter
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (auto num : nums)
        mp[num]++;

    for (auto i : mp)
        if (i.second > n / 2)
            return i.first;

    return -1;
}

// Alter
int majorityElement(vector<int> nums)
{
    sort(begin(nums), end(nums));
    return nums[nums.size() / 2];
}