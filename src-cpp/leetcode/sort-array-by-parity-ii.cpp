#include <bits/stdc++.h>
using namespace std;

// 2ptr inplace
vector<int> sortArrayByParityII(vector<int> &nums)
{
    int n = nums.size();
    int e = 0, o = 1;

    while (e < n && o < n)
    {
        if (nums[e] % 2 == 0)
            e += 2;
        else if (nums[o] % 2 == 1)
            o += 2;
        else
            swap(nums[e], nums[o]);
    }

    return nums;
}

// minimalistic inplace
vector<int> sortArrayByParityII(vector<int> &nums)
{
    int n = size(nums);
    for (int i = 0, j = 0; i < n && j < n;)
        swap(
            *find_if(begin(nums) + i, end(nums), [&i, &n](int v)
                     { return (i++ % 2 == 0 && v % 2 != 0) || i == n; }),

            *find_if(begin(nums) + j, end(nums), [&j, &n](int v)
                     { return (j++ % 2 != 0 && v % 2 == 0) || j == n; }));

    return nums;
}

// 2 ptr
vector<int> sortArrayByParityII(vector<int> &nums)
{
    int n = size(nums);
    vector<int> res(n, -1);
    int e = 0, o = 1;

    for (auto num : nums)
    {
        if (num % 2 == 0)
            res[e] = num, e += 2;
        else
            res[o] = num, o += 2;
    }

    return res;
}