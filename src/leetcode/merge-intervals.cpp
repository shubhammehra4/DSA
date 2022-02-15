#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
};

vector<Interval> mergeIntervals(vector<Interval> &intervals)
{
    if (intervals.empty())
        return vector<Interval>{};

    vector<Interval> res;

    sort(begin(intervals), end(intervals), [](Interval a, Interval b)
         { return a.start < b.start; });

    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (res.back().end < intervals[i].start)
            res.push_back(intervals[i]);
        else
            res.back().end = max(res.back().end, intervals[i].end);
    }

    return res;
}

// leetcode
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals;

    vector<vector<int>> result;
    sort(begin(intervals), end(intervals));
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (result.back()[1] >= intervals[i][0])
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        else
            result.push_back(intervals[i]);
    }

    return result;
}