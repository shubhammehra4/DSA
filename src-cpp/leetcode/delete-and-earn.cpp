#include <bits/stdc++.h>
using namespace std;

// dp - space-optimised
int deleteAndEarn(vector<int> &nums)
{
    int n = 10001;

    vector<int> sum(n, 0);
    for (auto num : nums)
        sum[num] += num;

    int skip = 0;
    int take = sum[1];

    for (int i = 2; i < n; i++)
    {
        auto temp = max(sum[i] + skip, take);
        skip = take;
        take = temp;
    }

    return take;
}

// dp
int deleteAndEarn(vector<int> &nums)
{
    int n = 10001;

    vector<int> sum(n, 0);
    for (auto num : nums)
        sum[num] += num;

    vector<int> dp(n, 0);

    dp[0] = 0;
    dp[1] = sum[1];

    for (int i = 2; i < n; i++)
        dp[i] = max(sum[i] + dp[i - 2], dp[i - 1]);

    return dp[n - 1];
}

// brute-force
int deleteAndEarn(vector<int> &nums)
{
    int n = nums.size();
    sort(begin(nums), end(nums));

    function<int(int)> solve = [&nums, &n, &solve](int index) -> int
    {
        if (index >= n)
            return 0;

        int currValue = nums[index];
        int currSum = currValue;
        int i = index + 1;

        while (i < n && nums[i] == currValue)
            currSum += currValue, i++;

        while (i < n && nums[i] == currValue + 1)
            i++;

        return max(currSum + solve(i), solve(index + 1));
    };

    return solve(0);
}