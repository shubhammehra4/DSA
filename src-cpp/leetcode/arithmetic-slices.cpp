#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{
    int res = 0;
    for (auto i = 2, j = 1; i < nums.size(); ++i)
    {
        if (nums[i] - nums[i - 1] != nums[j] - nums[j - 1])
            j = i;

        res += i - j;
    }

    return res;
}

// alter
int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();

    int res = 0;
    int prevDiff = nums[1] - nums[0];
    int cnt = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int currDiff = nums[i + 1] - nums[i];

        if (currDiff == prevDiff)
            cnt++;
        else
        {
            prevDiff = currDiff;
            cnt = 0;
        }

        res += cnt;
    }

    return res;
}

// brute-force
int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;

    int res = 0;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (nums[i + 1] - nums[i] == nums[j] - nums[j - 1])
                res++;
            else
                break;
        }
    }

    return res;
}
