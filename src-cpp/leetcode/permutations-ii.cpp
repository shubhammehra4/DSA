#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>> &res, vector<int> &nums, unordered_map<int, int> &mp, vector<int> &perm)
{
    if (perm.size() == nums.size())
    {
        res.push_back(perm);
        return;
    }

    for (auto &[num, freq] : mp)
    {
        if (freq != 0)
        {
            freq--;
            perm.push_back(num);
            backtrack(res, nums, mp, perm);
            perm.pop_back();
            freq++;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> perm;
    unordered_map<int, int> mp;

    for (auto num : nums)
        mp[num]++;

    backtrack(res, nums, mp, perm);

    return res;
}