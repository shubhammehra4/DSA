#include <bits/stdc++.h>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    int n = nums.size();
    int bucket[102] = {0};

    for (auto i : nums)
        bucket[i + 1]++;

    for (int i = 1; i < 102; i++)
        bucket[i] += bucket[i - 1];

    for (int i = 0; i < n; i++)
        nums[i] = bucket[nums[i]];

    return nums;
}

int main()
{
    return 0;
}