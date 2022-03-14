#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    if (nums.empty())
        return {};

    int n = nums.size();
    sort(begin(nums), end(nums));
    vector<vector<int>> result;

    for (int i = 0; i < n; ++i)
    {
        // all numbers from now on will be greater than 0, no point in continuing
        if (nums[i] > 0)
            break;

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0)
                ++left;
            else if (sum > 0)
                --right;
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});

                int last_left = nums[left], last_right = nums[right];

                // we have seen this number & combo before; skip
                while (left < right && nums[left] == last_left)
                    ++left;
                while (left < right && nums[right] == last_right)
                    --right;
            }
        }
    }

    return result;
}

// brute force
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
                if (nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({i, j, k});
        }
    }

    return res;
}