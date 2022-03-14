#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int curSum = 0, maxSum = INT_MIN;

    for (auto num : nums)
    {
        curSum += num;
        maxSum = max(maxSum, curSum);

        if (curSum < 0)
            curSum = 0;
    }

    return maxSum;
}

// alter
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