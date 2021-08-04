#include <bits/stdc++.h>
using namespace std;

// Also Solved using bit manipulation
vector<vector<int>> ans;
void helper(vector<int> &nums, vector<int> &subset, int index)
{
    ans.push_back(subset);
    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;

        subset.push_back(nums[i]);
        helper(nums, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> subset = {};
    helper(nums, subset, 0);
    return ans;
}

int main()
{
    vector<int> array = {1, 2, 2};

    vector<vector<int>> res = subsetsWithDup(array);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}
