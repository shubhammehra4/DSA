#include <bits/stdc++.h>
using namespace std;

// stack
bool find132pattern(vector<int> &nums)
{
    int n = size(nums);
    int num3 = INT_MIN;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        int num1 = nums[i];

        if (num1 < num3)
            return true;
        else
            while (!st.empty() && num1 > st.top())
            {
                num3 = st.top();
                st.pop();
            }

        st.push(num1);
    }
    return false;
}

// 2 ptr
bool find132pattern(vector<int> &nums)
{
    int n = size(nums);
    int minLeft = nums[0];

    for (int j = 0; j < n - 1; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (nums[k] > minLeft && nums[j] > nums[k])
                return true;

            minLeft = min(minLeft, nums[j]);
        }
    }

    return false;
}

// brute-force
bool find132pattern(vector<int> &nums)
{
    int n = size(nums);

    for (int j = 1; j < n - 1; j++)
    {
        for (int i = 0; i < j; i++)
            if (nums[i] < nums[j])
                for (int k = j + 1; k < n; k++)
                    if (nums[i] < nums[k] && nums[k] < nums[j])
                        return true;
    }

    return false;
}