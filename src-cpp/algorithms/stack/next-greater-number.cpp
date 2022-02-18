#include <bits/stdc++.h>
using namespace std;

// in both directions
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);
    stack<int> s;
    // iterate as if a duplicate was pushed to the existing array
    for (int i = (2 * n) - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums[i % n])
            s.pop();

        res[i % n] = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
    }

    return res;
}

// Only to the right
vector<int> nextGreaterElement(vector<int> &nums)
{
    vector<int> ans(nums.size());
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums[i])
            s.pop(); // short one go away while blocked

        ans[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }

    return ans;
}