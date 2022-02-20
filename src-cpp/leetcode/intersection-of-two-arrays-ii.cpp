#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> dict;
    vector<int> res;
    for (auto num : nums1)
        dict[num]++;

    for (auto num : nums2)
        if (dict.find(num) != dict.end() && --dict[num] >= 0)
            res.push_back(num);

    return res;
}

// Case: arrays are sorted
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));

    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> res;

    while (i < n1 && j < n2)
    {
        if (nums1[i] == nums2[j])
        {
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] > nums2[j])
            j++;
        else
            i++;
    }

    return res;
}