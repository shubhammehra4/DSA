#include <bits/stdc++.h>
using namespace std;

// backtracting swap
void permuteUtil(vector<int> &nums, int i, vector<vector<int>> &perms)
{
    if (i == nums.size())
        perms.push_back(nums);
    else
    {
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            permuteUtil(nums, i + 1, perms);
            swap(nums[i], nums[j]);
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> perms;
    permuteUtil(nums, 0, perms);
    return perms;
}

// backtracting bitset
void backtrack(vector<vector<int>> &res, vector<int> &nums, bitset<21> &bs, vector<int> &perm)
{
    if (perm.size() == nums.size())
    {
        res.push_back(perm);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (bs.test(nums[i] + 10) != 1)
        {
            perm.push_back(nums[i]);
            bs.set(nums[i] + 10, 1);

            backtrack(res, nums, bs, perm);

            bs.set(nums[i] + 10, 0);
            perm.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> perm;
    bitset<21> bs(0);

    backtrack(res, nums, bs, perm);

    return res;
}