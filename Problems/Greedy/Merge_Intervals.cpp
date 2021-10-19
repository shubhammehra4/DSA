#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals;

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (res.back()[1] >= intervals[i][0])
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        else
            res.push_back(intervals[i]);
    }

    return res;
}