#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int l = 0, r = nums.size() - 1;

    while (l < r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] < nums[m + 1])
            l = m + 1;
        else
            r = m;
    }

    return l;
}

// brute-force
int findPeakElement(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
        if (nums[i] > nums[i + 1])
            return i;

    return nums.size() - 1;
}