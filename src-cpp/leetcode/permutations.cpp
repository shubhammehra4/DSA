#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> perms;
    permute(nums, 0, perms);
    return perms;
}

void permute(vector<int> &nums, int i, vector<vector<int>> &perms)
{
    if (i == nums.size())
        perms.push_back(nums);
    else
    {
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            permute(nums, i + 1, perms);
            swap(nums[i], nums[j]);
        }
    }
}

// backtracting
void backtrack(vector<vector<int>> &res, vector<int> &nums, bitset<21> &bs, vector<int> &temp)
{
    if (temp.size() == nums.size())
    {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (bs.test(nums[i] + 10) != 1)
        {
            temp.push_back(nums[i]);
            bs.set(nums[i] + 10);

            backtrack(res, nums, bs, temp);

            bs.flip(nums[i] + 10);
            temp.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    bitset<21> bs(0);

    backtrack(res, nums, bs, temp);

    return res;
}