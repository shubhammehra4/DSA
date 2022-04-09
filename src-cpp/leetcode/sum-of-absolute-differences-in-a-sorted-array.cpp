#include <bits/stdc++.h>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int> &nums)
{
    int n = nums.size();
    int totaSum = accumulate(begin(nums), end(nums), 0);

    vector<int> res;
    for (auto num : nums)
        res.push_back(abs(n * num - totaSum));

    return res;
}