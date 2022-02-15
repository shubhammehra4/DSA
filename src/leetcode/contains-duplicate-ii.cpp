#include <bits/stdc++.h>
using namespace std;

// Time Efficient
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> idxMap;
    for (int i = 0; i < nums.size(); i++)
    {
        if (idxMap.find(nums[i]) != idxMap.end() && i - idxMap[nums[i]] <= k)
            return true;

        idxMap[nums[i]] = i;
    }

    return false;
}

// Space Efficient
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k)
            st.erase(nums[i - k - 1]);

        if (st.insert(nums[i]).second == false) // already present
            return true;
    }

    return false;
}