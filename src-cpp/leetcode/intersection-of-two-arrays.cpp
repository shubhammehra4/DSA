#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> s(begin(nums1), end(nums1));
    vector<int> res;

    for (auto num : nums2)
    {
        if (s.find(num) != end(s))
        {
            res.push_back(num);
            s.erase(num);
        }
    }

    return res;
}