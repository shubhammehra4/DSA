#include <bits/stdc++.h>
using namespace std;

// bfs
int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<int> direction = {0, 1, 0, -1, 0};
    auto outOfBounds = [&m, &n](int row, int col) -> bool
    {
        return row < 0 || col < 0 || row > m - 1 || col > n - 1;
    };

    int res = 0;
    queue<pair<int, int>> q;

    for (auto i = 0; i < m; ++i)
    {
        for (auto j = 0; j < n; ++j)
        {
            res += grid[i][j];
            if (i * j == 0 || i == m - 1 || j == n - 1) // top, left, right or bottom border
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        auto row = q.front().first;
        auto col = q.front().second;
        q.pop();

        if (outOfBounds(row, col) || grid[row][col] != 1)
            continue;

        grid[row][col] = 0;
        res--;
        for (int d = 0; d < 4; d++)
        {
            int r = row + direction[d];
            int c = col + direction[d + 1];

            q.push({r, c});
        }
    }

    return res;
}

// dfs
int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<int> direction = {0, 1, 0, -1, 0};
    auto outOfBounds = [&m, &n](int row, int col) -> bool
    {
        return row < 0 || col < 0 || row > m - 1 || col > n - 1;
    };

    function<void(int, int)> dfs =
        [&grid, &direction, &outOfBounds, &dfs](int row, int col) -> void
    {
        grid[row][col] = 0;

        for (int d = 0; d < 4; d++)
        {
            int r = row + direction[d];
            int c = col + direction[d + 1];

            if (!outOfBounds(r, c) && grid[r][c] == 1)
                dfs(r, c);
        }
    };

    for (int i = 0; i < m; i++)
    {
        if (grid[i][0] == 1)
            dfs(i, 0); // left border
        if (grid[i][n - 1] == 1)
            dfs(i, n - 1); // right border
    }

    for (int j = 0; j < n; j++)
    {
        if (grid[0][j] == 1)
            dfs(0, j); // top border
        if (grid[m - 1][j] == 1)
            dfs(m - 1, j); // bottom border
    }

    int res = 0;

    for (auto &row : grid)
        for (auto cell : row)
            if (cell == 1)
                res++;

    return res;
}