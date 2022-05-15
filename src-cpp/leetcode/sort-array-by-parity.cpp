#include <bits/stdc++.h>
using namespace std;

// stl partition
vector<int> sortArrayByParity(vector<int> &nums)
{
    constexpr auto is_even = [](auto e)
    { return (e & 1) == 0; };

    partition(begin(nums), end(nums), is_even);
    return nums;
}

// swap
vector<int> sortArrayByParity(vector<int> &nums)
{
    for (int i = 0, j = 0; j < nums.size(); j++)
        if ((nums[j] & 1) == 0)
            swap(nums[i++], nums[j]);

    return nums;
}

// naive
vector<int> sortArrayByParity(vector<int> &nums)
{
    sort(begin(nums), end(nums), [](const int a, const int b) -> bool
         { return (a & 1) < (b & 1); });

    return nums;
}