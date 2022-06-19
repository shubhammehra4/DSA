#include <bits/stdc++.h>
using namespace std;

// 2 ptr
int trap(vector<int> &height)
{
    int n = size(height);
    int res = 0;
    int l = 0, r = n - 1;

    int maxLeft = 0, maxRight = 0;
    while (l <= r)
    {
        // there exists a block to the right with greater or equal height
        if (height[l] <= height[r])
        {
            if (height[l] >= maxLeft)
                maxLeft = height[l];
            else
                res += maxLeft - height[l];

            l++;
        }
        else
        {
            if (height[r] >= maxRight)
                maxRight = height[r];
            else
                res += maxRight - height[r];

            r--;
        }
    }

    return res;
}

// 2 ptr alter
int trap(vector<int> &height)
{
    int n = size(height);
    int res = 0, minHeight = 0;

    int l = 0, r = n - 1;
    while (l < r)
    {
        while (l < r && height[l] <= minHeight)
            res += minHeight - height[l++];

        while (l < r && height[r] <= minHeight)
            res += minHeight - height[r--];

        minHeight = min(height[l], height[r]);
    }

    return res;
}

// prefix and sufffix
int trap(vector<int> &height)
{
    int n = size(height);
    vector<int> prefix(n), suffix(n); // maxLeft and maxRight

    prefix[0] = height[0];
    for (int i = 1; i < n; i++)
        prefix[i] = max(prefix[i - 1], height[i]);

    suffix[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = max(suffix[i + 1], height[i]);

    int res = 0;
    for (int i = 0; i < n; i++)
        res += min(prefix[i], suffix[i]) - height[i];

    return res;
}

// brute-force
int trap(vector<int> &height)
{
    int n = size(height);
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int maxLeft = 0, maxRight = 0;
        int j = i;
        while (j >= 0)
        {
            maxLeft = max(maxLeft, height[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            maxRight = max(maxRight, height[j]);
            j++;
        }

        res += min(maxLeft, maxRight) - height[i];
    }

    return res;
}