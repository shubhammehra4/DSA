#include <bits/stdc++.h>
using namespace std;

// tabulation with restoration
// t - O(n*n), s - O(n)
vector<int> getLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }

    int res = dp[0], pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i] > res)
        {
            res = dp[i];
            pos = i;
        }
    }

    vector<int> subseq;
    while (pos != -1)
    {
        subseq.push_back(nums[pos]);
        pos = parent[pos];
    }

    reverse(begin(subseq), end(subseq));
    return subseq;
}

// tabulation
// t - O(n*n), s - O(n)
int lengthOfLIS(vector<int> &nums)
{
    int res = 1;
    int n = nums.size();

    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(res, dp[i]);
            }

    return res;
}

// memoization - space optimised
// t - O(n*n), s - O(n)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> memo(n + 1, -1);

    function<int(int, int)> lisUtil = [&nums, &memo, &lisUtil](int idx, int prevIdx) -> int
    {
        if (idx >= nums.size())
            return 0;

        if (memo[prevIdx + 1] != -1)
            return memo[prevIdx + 1];

        int skipCurrent = lisUtil(idx + 1, prevIdx);

        int takeCurent = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
            takeCurent = 1 + lisUtil(idx + 1, idx);

        memo[prevIdx + 1] = max(skipCurrent, takeCurent);

        return memo[prevIdx + 1];
    };

    return lisUtil(0, -1);
}

// memoization
// t - O(n*n), s - O(n*n)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> memo(n, vector<int>(n + 1, -1));

    function<int(int, int)> lisUtil = [&nums, &memo, &lisUtil](int idx, int prevIdx) -> int
    {
        if (idx >= nums.size())
            return 0;

        if (memo[idx][prevIdx + 1] != -1)
            return memo[idx][prevIdx + 1];

        int skipCurrent = lisUtil(idx + 1, prevIdx);

        int takeCurent = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
            takeCurent = 1 + lisUtil(idx + 1, idx);

        memo[idx][prevIdx + 1] = max(skipCurrent, takeCurent);

        return memo[idx][prevIdx + 1];
    };

    return lisUtil(0, -1);
}

// brute-force
// t - O(2^n), s - O(2^n)
int lengthOfLIS(vector<int> &nums, int idx = 0, int prevIdx = -1)
{
    if (idx == nums.size())
        return 0;

    int skipCurrent = lengthOfLIS(nums, idx + 1, prevIdx);

    int takeCurrent = 0;
    if (prevIdx == -1 || nums[idx] > nums[prevIdx])
        takeCurrent = 1 + lengthOfLIS(nums, idx + 1, idx);

    return max(skipCurrent, takeCurrent);
}