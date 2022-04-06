#include <bits/stdc++.h>
using namespace std;

// flood fill
// remove zeroes connected to edges
int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int islands = 0;

    function<int(int, int)> fill = [&grid, &fill, n, m](int r, int c) -> int
    {
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 1)
            return 0;

        grid[r][c] = 1;

        return 1 + fill(r + 1, c) + fill(r, c + 1) + fill(r - 1, c) + fill(r, c - 1);
    };

    // remove zeroes connected to the edges
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i * j == 0 || i == n - 1 || j == m - 1)
                fill(i, j);

    // count remaining islands
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 0 && fill(i, j) > 0)
                islands++;

    return islands;
}

// dfs
int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int islands = 0;

    function<bool(int, int)> dfs = [&grid, &dfs, n, m](int r, int c) -> bool
    {
        if (r < 0 || c < 0 || r >= n || c >= m)
            return false;

        if (grid[r][c] == 1)
            return true;

        grid[r][c] = 1;

        // Note: calling all 4 direction first to make sure that all the
        // 0's are marked as 1's so we dont visit/check them again even if one of them returns false
        bool d1 = dfs(r + 1, c);
        bool d2 = dfs(r, c + 1);
        bool d3 = dfs(r - 1, c);
        bool d4 = dfs(r, c - 1);
        return d1 && d2 && d3 && d4;
    };

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            if (grid[r][c] == 0 && dfs(r, c))
                islands++;

    return islands;
}