#include <bits/stdc++.h>
using namespace std;

// similar to lis
int maximumSumIncreasingSubsequence(vector<int> &nums)
{
    int res = 1;
    int n = nums.size();

    vector<int> dp(nums);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + nums[i]);
                res = max(res, dp[i]);
            }

    return res;
}