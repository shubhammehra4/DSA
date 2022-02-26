#include <bits/stdc++.h>
using namespace std;

// iterative dp
int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int a = 0, b = 0;

    for (auto num : nums)
    {
        int tmp = a;
        a = max(b + num, a);
        b = tmp;
    }

    return a;
}

// recursive memo/dp
int rob(vector<int> &nums)
{
    vector<int> memo(nums.size(), -1);
    function<int(int)> robUtil = [&nums, &memo, &robUtil](int i) -> int
    {
        if (i < 0)
            return 0;

        if (memo[i] >= 0)
            return memo[i];

        memo[i] = max(robUtil(i - 2) + nums[i], robUtil(i - 1));
        return memo[i];
    };

    return robUtil(nums.size() - 1);
}

// naive-2 tle bf
int rob(vector<int> &nums)
{
    function<int(int)> robUtil = [&nums, &robUtil](int i) -> int
    {
        if (i < 0)
            return 0;

        return max(robUtil(i - 2) + nums[i], robUtil(i - 1));
    };

    return robUtil(nums.size() - 1);
}

// naive tle bf
int rob(vector<int> &nums)
{
    function<int(int, int, bool)> robUtil = [&nums, &robUtil](int i, int money, bool canRob) -> int
    {
        if (i == nums.size())
            return money;

        if (canRob)
        {
            return max(robUtil(i + 1, money + nums[i], false), robUtil(i + 1, money, true));
        }

        return robUtil(i + 1, money, true);
    };

    return robUtil(0, 0, true);
}