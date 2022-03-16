#include <bits/stdc++.h>
using namespace std;

// monotonic stack
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n * 2; ++i)
    {
        while (!st.empty() && nums[st.top()] < nums[i % n])
        {
            res[st.top()] = nums[i % n];
            st.pop();
        }

        st.push(i % n);
    }

    return res;
}

// brute-force
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        res[i] = -1;

        for (int j = 1; j < n; j++)
        {
            if (nums[(i + j) % n] > nums[i])
            {
                res[i] = nums[(i + j) % n];
                break;
            }
        }
    }

    return res;
}