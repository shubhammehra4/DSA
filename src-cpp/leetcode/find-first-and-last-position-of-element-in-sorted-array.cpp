#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    auto lowerBound = lower_bound(begin(nums), end(nums), target);
    if (lowerBound == end(nums) || nums[lowerBound - begin(nums)] != target)
        return {-1, -1};

    auto upperBound = upper_bound(begin(nums), end(nums), target);

    return {(int)(lowerBound - begin(nums)), (int)(upperBound - begin(nums) - 1)};
}

vector<int> searchRange(vector<int> &nums, int target)
{
    auto bounds = equal_range(nums.begin(), nums.end(), target);
    if (bounds.first == bounds.second)
        return {-1, -1};
    return {(int)(bounds.first - nums.begin()), (int)(bounds.second - nums.begin() - 1)};
}
