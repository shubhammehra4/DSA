#include <bits/stdc++.h>
using namespace std;

// 1 pass
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m; // num->idx

    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
            return {i, m[target - nums[i]]};

        m[nums[i]] = i;
    }

    return {};
}

// 2 pass
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> m; // num->idx

    for (int i = 0; i < nums.size(); i++)
        m[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++)
        if (m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i)
            return {i, m[target - nums[i]]};

    return {};
}