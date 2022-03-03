#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(begin(intervals), end(intervals), [](vector<int> &a, vector<int> &b) -> bool
         { return a[1] < b[1]; });

    int res = 0;
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < end)
            res++;
        else
            end = intervals[i][1];
    }

    return res;
}