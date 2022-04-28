#include <bits/stdc++.h>
using namespace std;

// divide-and-conquer
int maxSubArray(vector<int> &nums, int l, int r)
{
    if (l > r)
        return INT_MIN;

    int m = l + (r - l) / 2;
    int ml = 0, mr = 0;
    int lmax = maxSubArray(nums, l, m - 1);
    int rmax = maxSubArray(nums, m + 1, r);

    for (int i = m - 1, sum = 0; i >= l; i--)
    {
        sum += nums[i];
        ml = max(sum, ml);
    }

    for (int i = m + 1, sum = 0; i <= r; i++)
    {
        sum += nums[i];
        mr = max(sum, mr);
    }

    return max(max(lmax, rmax), ml + mr + nums[m]);
}
int maxSubArray(vector<int> &nums)
{
    return maxSubArray(nums, 0, nums.size() - 1);
}

// space optimised dp
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0, maxSum = INT_MIN;

    for (auto num : nums)
    {
        sum += num;
        maxSum = max(maxSum, sum);

        if (sum < 0)
            sum = 0;
    }

    return maxSum;
}

// brute-force
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> s(n);
    s[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] > 0)
            s[i] = s[i - 1] + nums[i];
        else
            s[i] = nums[i];
    }

    sort(begin(s), end(s));

    return s.back();
}