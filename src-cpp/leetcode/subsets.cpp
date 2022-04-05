#include <bits/stdc++.h>
using namespace std;

// bit-manipulation
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subsetsSize = 1 << n;

    auto includeInIthSubset = [](int mask, int i) -> bool
    { return (mask >> i) & 1; };

    vector<vector<int>> subs(subsetsSize);
    for (int mask = 0; mask < subsetsSize; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (includeInIthSubset(mask, i))
                subs[mask].push_back(nums[i]);
        }
    }

    return subs;
}

// iterative
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subs = {{}};

    for (auto num : nums)
    {
        int n = subs.size();
        for (int i = 0; i < n; i++)
        {
            subs.push_back(subs[i]);
            subs.back().push_back(num);
            // Alter for understanding
            // auto subset = subs[i];
            // subset.push_back(num);
            // subs.push_back(subset);
        }
    }

    return subs;
}

// recursive - backtracking
void subsets(vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &subs)
{
    subs.push_back(sub);
    for (int j = i; j < nums.size(); j++)
    {
        sub.push_back(nums[j]);
        subsets(nums, j + 1, sub, subs);
        sub.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> subs;
    vector<int> sub;
    subsets(nums, 0, sub, subs);
    return subs;
}
