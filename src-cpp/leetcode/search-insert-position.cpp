#include <bits/stdc++.h>
using namespace std;

// lower-bound stl
int searchInsert(vector<int> &nums, int target)
{
    return lower_bound(begin(nums), end(nums), target) - begin(nums);
}

// binary-search
int searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = left + ((right - left) / 2);

        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return nums[left] >= target ? left : left + 1;
}