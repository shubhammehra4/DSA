#include <bits/stdc++.h>
using namespace std;

// 2-ptr
void sortColors(vector<int> &nums)
{
    int n = size(nums);
    int l = 0, m = 0, h = n - 1;

    while (m <= h)
    {
        if (nums[m] == 0)
        {
            swap(nums[l], nums[m]);
            l++, m++;
        }
        else if (nums[m] == 1)
            m++;
        else
        {
            swap(nums[m], nums[h]);
            h--;
        }
    }
}

// brute force
void sortColors(vector<int> &nums)
{
    sort(begin(nums), end(nums));
}