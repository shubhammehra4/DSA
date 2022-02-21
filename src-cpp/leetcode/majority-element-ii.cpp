#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int count1 = 0, count2 = 0;
    int candidate1 = -1, candidate2 = -1;
    int n = nums.size();

    for (auto num : nums)
    {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
        else if (count1 == 0)
            candidate1 = num, count1 = 1;
        else if (count2 == 0)
            candidate2 = num, count2 = 1;
        else
            count1--, count2--;
    }

    if (candidate1 == candidate2)
        return {candidate1};

    vector<int> res;

    for (auto c : {candidate1, candidate2})
        if (count(begin(nums), end(nums), c) > n / 3)
            res.push_back(c);

    return res;
}

// Alter
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    vector<int> res;

    for (auto num : nums)
        mp[num]++;

    for (auto i : mp)
        if (i.second > n / 3)
            res.push_back(i.first);

    return res;
}