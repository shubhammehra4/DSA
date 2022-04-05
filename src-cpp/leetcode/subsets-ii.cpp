#include <bits/stdc++.h>
using namespace std;

// backtracking
void subsetsWithDup(vector<int> &nums, int i, vector<int> &sub, vector<vector<int>> &subs)
{
    subs.push_back(sub);
    for (int j = i; j < nums.size(); j++)
    {
        if (j == i || nums[j] != nums[j - 1])
        {
            sub.push_back(nums[j]);
            subsetsWithDup(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> subs;
    sort(begin(nums), end(nums));
    vector<int> sub;
    subsetsWithDup(nums, 0, sub, subs);
    return subs;
}

// bit-manipulation hash-set
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    int n = nums.size();
    int subsetsSize = 1 << n;
    sort(begin(nums), end(nums));
    vector<vector<int>> subs;
    unordered_set<string> seen;

    auto includeInIthSubset = [](int mask, int i) -> bool
    { return (mask >> i) & 1; };

    for (int mask = 0; mask < subsetsSize; ++mask)
    {
        vector<int> subset;
        string hash = "";
        for (int i = 0; i < n; i++)
        {
            if (includeInIthSubset(mask, i))
            {
                subset.push_back(nums[i]);
                hash += to_string(nums[i]) + ",";
            }
        }

        if (seen.count(hash) == 0)
        {
            subs.push_back(subset);
            seen.insert(hash);
        }
    }

    return subs;
}
