#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int first = INT_MAX, mid = INT_MAX;

    for (auto last : nums)
    {
        if (last <= first)
            first = last;
        else if (last <= mid)
            mid = last;
        else
            return true;
    }

    return false;
}

// brute-force
bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] < nums[j])
            {
                for (int k = j + 1; k < n; k++)
                    if (nums[j] < nums[k])
                        return true;
            }
        }
    }

    return false;
}