#include <bits/stdc++.h>
using namespace std;

// binary-search
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> newInterval)
{
    auto compare = [](const vector<int> &intv1, const vector<int> &intv2)
    { return intv1[1] < intv2[0]; };

    auto range = equal_range(begin(intervals), end(intervals), newInterval, compare);

    auto lowerBound = range.first;
    auto upperBound = range.second;

    if (lowerBound == upperBound)
        intervals.insert(lowerBound, newInterval);
    else
    {
        int startIdx = lowerBound - begin(intervals);
        int endIdx = upperBound - begin(intervals) - 1;

        intervals[endIdx][0] = min(newInterval[0], intervals[startIdx][0]);
        intervals[endIdx][1] = max(newInterval[1], intervals[endIdx][1]);

        intervals.erase(lowerBound, upperBound - 1);
    }

    return intervals;
}

// linear
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> res;
    int n = intervals.size();
    int i = 0;

    // Left part (no intersection with newInterval)
    while (i < n && intervals[i][1] < newInterval[0])
    {
        res.push_back(intervals[i]);
        ++i;
    }

    // newInterval part (with or without merge)
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        ++i;
    }
    res.push_back(newInterval);

    // Right part (no intersection with newInterval)
    while (i < n && intervals[i][0] > newInterval[1])
    {
        res.push_back(intervals[i]);
        ++i;
    }

    return res;
}