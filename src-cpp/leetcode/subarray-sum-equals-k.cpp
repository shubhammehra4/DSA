#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int sum = 0; // running sum
    int res = 0;

    mp[0] = 1;

    for (auto num : nums)
    {
        sum += num;

        if (mp.count(sum - k))
            res += mp[sum - k];

        mp[sum]++;
    }

    return res;
}

// brute-force
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = nums[i];

        if (sum == k)
            res++;

        for (int j = i + 1; j < n; j++)
        {
            sum += nums[j];

            if (sum == k)
                res++;
        }
    }

    return res;
}