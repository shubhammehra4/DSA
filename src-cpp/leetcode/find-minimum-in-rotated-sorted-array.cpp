#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();

    int l = 0;
    int r = n - 1;

    while (l < r && nums[l] > nums[r])
    {
        int mid = (l + r) / 2;

        if (nums[mid] > nums[r])
            l = mid + 1;
        else
            r = mid;
    }

    return nums[l];
}