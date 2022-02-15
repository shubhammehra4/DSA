#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> sumMp;

    for (auto k : nums3)
        for (auto l : nums4)
            sumMp[k + l]++;

    int count = 0;

    for (auto i : nums1)
        for (auto j : nums2)
            count += sumMp[-(i + j)];

    return count;
}