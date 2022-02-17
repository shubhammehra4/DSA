#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &h)
{
    vector<int> heights(begin(h), end(h));
    heights.push_back(0);
    stack<int> st;
    int ans = 0;

    for (int right = 0; right < heights.size(); right++)
    {
        while (!st.empty() && heights[st.top()] > heights[right])
        {
            int height = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();

            ans = max(ans, height * (right - left - 1));
        }

        st.push(right);
    }

    return ans;
}

int largestRectangleAreaAlter(vector<int> &heights)
{
    stack<int> st;
    int ans = 0;
    int n = heights.size();

    for (int right = 0; right <= heights.size(); right++)
    {
        while (!st.empty() && (right == n || heights[st.top()] > heights[right]))
        {
            int height = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();

            ans = max(ans, height * (right - left - 1));
        }

        st.push(right);
    }

    return ans;
}