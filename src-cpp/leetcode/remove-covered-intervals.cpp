#include <bits/stdc++.h>
using namespace std;

int removeCoveredIntervals(vector<vector<int>> &intervals)
{
    sort(begin(intervals), end(intervals));
    int res = 0;
    int left = -1, right = -1;

    for (auto &interval : intervals)
    {
        if (interval[0] > left && interval[1] > right)
        {
            left = interval[0];
            res += 1;
        }

        right = max(right, interval[1]);
    }

    return res;
}