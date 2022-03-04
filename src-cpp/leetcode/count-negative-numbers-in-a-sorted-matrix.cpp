#include <bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int r = 0, c = n - 1;

    int ans = 0;

    while (r < m)
    {
        while (c >= 0 && grid[r][c] < 0)
            --c;

        ans += n - c - 1;
        ++r;
    }

    return ans;
}

int countNegatives(vector<vector<int>> &grid)
{
    int res = 0;

    for (auto &row : grid)
    {
        auto it = upper_bound(rbegin(row), rend(row), -1);
        res += it - rbegin(row);
    }

    return res;
}
