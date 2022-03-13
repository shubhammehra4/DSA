#include <bits/stdc++.h>
using namespace std;

// xor
// diving into 2 groups
vector<int> singleNumber(vector<int> &nums)
{
    long int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    // Get its last set bit
    diff &= -diff;

    vector<int> res = {0, 0};
    for (auto num : nums)
    {
        // group 1
        if ((num & diff) == 0) // the bit is not set
            res[0] ^= num;
        // group 2
        else
            res[1] ^= num;
    }

    return res;
}

// set
vector<int> singleNumber(vector<int> &nums)
{
    unordered_set<int> s;

    for (auto num : nums)
    {
        if (s.find(num) == s.end())
            s.insert(num);
        else
            s.erase(num);
    }

    vector<int> res;
    for (auto num : s)
        res.push_back(num);

    return res;
}

// hash map
vector<int> singleNumber(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (auto num : nums)
        mp[num]++;

    vector<int> res;
    for (auto [num, f] : mp)
        if (f == 1)
            res.push_back(num);

    return res;
}