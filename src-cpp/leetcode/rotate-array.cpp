#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    reverse(begin(nums), end(nums));

    reverse(begin(nums), begin(nums) + k);
    reverse(begin(nums) + k, end(nums));
}