#include <bits/stdc++.h>
using namespace std;

// [4,6,7,7]
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> seq;

    function<void(int)> dfs = [&](int pos) -> void
    {
        if (seq.size() > 1)
            res.push_back(seq);

        unordered_set<int> hash; // way to deal with duplicate sub-sequences
        for (int i = pos; i < nums.size(); ++i)
        {
            if ((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end())
            {
                seq.push_back(nums[i]);
                dfs(i + 1);
                seq.pop_back();
                hash.insert(nums[i]);
            }
        }
    };

    dfs(0);
    return res;
}
