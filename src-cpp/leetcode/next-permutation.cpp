#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i = n - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) // find first decreasing num from right
        i--;

    if (i >= 0)
    {
        int j = n - 1;
        while (nums[j] <= nums[i]) // num just greater than nums[i]
            j--;

        swap(nums[i], nums[j]);
    }

    reverse(begin(nums) + i + 1, end(nums));
}