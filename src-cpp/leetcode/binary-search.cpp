#include <bits/stdc++.h>
using namespace std;

// less operations
int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    int mid;

    while (l < r)
    {
        mid = l + (r - l) / 2;

        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return nums[l] == target ? l : -1;
}