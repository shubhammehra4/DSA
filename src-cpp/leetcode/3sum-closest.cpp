#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(begin(nums), end(nums));

    int sum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; ++i)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum3 = nums[i] + nums[l] + nums[r];

            if (sum3 == target)
                return sum3;

            if (abs(sum - target) > abs(sum3 - target))
                sum = sum3;

            if (sum3 > target)
                --r;
            else
                ++l;
        }
    }

    return sum;
}

// brute force
int threeSumClosest(vector<int> &nums, int target)
{
    int sum = 0;
    int minDiff = INT_MAX;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
                if (abs(nums[i] + nums[j] + nums[k] - target) < minDiff)
                {
                    sum = nums[i] + nums[j] + nums[k];
                    minDiff = abs(sum - target);
                }
        }
    }

    return sum;
}