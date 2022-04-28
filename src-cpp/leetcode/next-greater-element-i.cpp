#include <bits/stdc++.h>
using namespace std;

// monotonic stack
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    unordered_map<int, int> mp; // num->greaterNum
    stack<int> st;

    for (auto num : nums2)
    {
        while (!st.empty() && st.top() < num)
        {
            mp[st.top()] = num;
            st.pop();
        }

        st.push(num);
    }

    vector<int> res;
    for (auto num : nums1)
        res.push_back(mp.count(num) ? mp[num] : -1);

    return res;
}

// brute-force
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    unordered_map<int, int> mp; // num->greaterNum
    mp[nums2.back()] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;

        while (j < n && nums2[j] <= nums2[i])
            j++;

        mp[nums2[i]] = j < n ? nums2[j] : -1;
    }

    vector<int> res;
    for (auto num : nums1)
        res.push_back(mp[num]);

    return res;
}