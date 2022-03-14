#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    int i = 0, j = n - 1;
    int maxRectArea = INT_MIN;

    while (i < j)
    {
        maxRectArea = max(maxRectArea, min(height[i], height[j]) * (j - i));

        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    return maxRectArea;
}

// brute force
int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxRectArea = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            maxRectArea = max(maxRectArea, min(height[i], height[j]) * (j - i));
        }
    }

    return maxRectArea;
}