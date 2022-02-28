#include <bits/stdc++.h>
using namespace std;

// bit manipulation
int singleNumber(vector<int> &nums)
{
    return reduce(begin(nums), end(nums), 0, bit_xor<>{});
}

// sorting
int singleNumber(vector<int> &nums)
{
    sort(begin(nums), end(nums));

    for (int i = 1; i < nums.size(); i += 2)
        if (nums[i] != nums[i - 1])
            return nums[i - 1];

    return nums[nums.size() - 1];
}

// hash map
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto num : nums)
        mp[num]++;

    for (auto f : mp)
        if (f.second == 1)
            return f.first;

    return -1;
}