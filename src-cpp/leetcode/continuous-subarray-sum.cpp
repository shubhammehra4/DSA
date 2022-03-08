#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < 2)
        return false;

    unordered_map<int, int> mp;
    int runningSum = 0;
    mp[0] = -1;

    for (int i = 0; i < n; i++)
    {
        runningSum += nums[i];

        if (k != 0)
            runningSum = runningSum % k;

        if (mp.find(runningSum) != mp.end())
        {
            if (i - mp[runningSum] > 1)
                return true;
        }
        else
            mp[runningSum] = i;
    }

    return false;
}