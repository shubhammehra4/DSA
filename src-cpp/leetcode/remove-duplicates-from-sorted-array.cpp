#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int k = 0;

    while (i < n)
    {
        auto num = nums[i];
        nums[k++] = num;

        while (i < n && nums[i] == num)
            i++;
    }

    return k;
}