#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
};

vector<Interval> intervalScheduling(vector<Interval> intervals)
{
    int n = intervals.size();
    sort(begin(intervals), end(intervals), [](auto a, auto b) -> bool
         { return a.end < b.end; });

    vector<Interval> res;
    res.push_back(intervals[0]);

    vector<int> start;
    for (auto interval : intervals)
        start.push_back(interval.start);

    auto end = intervals[0].end;

    for (int i = 1; i < n; i++)
    {
        if (start[i] >= end)
        {
            res.push_back(intervals[i]);
            end = intervals[i].end;
        }
    }

    return res;
}