#include <bits/stdc++.h>
using namespace std;

// bfs
int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> direction{-1, 0, 1, 0, -1};
    queue<pair<int, int>> q, q1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 1)
            {
                for (int d = 0; d < 4; d++)
                    q.push({i + direction[d], j + direction[d + 1]});
            }

    int dist = 0;
    while (!q.empty())
    {
        dist++;

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            if (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0)
            {
                grid[i][j] = dist;
                for (int d = 0; d < 4; d++)
                    q1.push({i + direction[d], j + direction[d + 1]});
            }
        }
        swap(q, q1);
    }

    return dist == 1 ? -1 : dist - 1;
}

// dfs
int maxDistance(vector<vector<int>> &grid, int mx = -1)
{
    int n = grid.size();

    function<void(int, int, int)> dfs = [&grid, &n, &dfs](int i, int j, int dist)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || (grid[i][j] != 0 && grid[i][j] <= dist))
            return;

        grid[i][j] = dist;

        dfs(i - 1, j, dist + 1);
        dfs(i + 1, j, dist + 1);
        dfs(i, j - 1, dist + 1);
        dfs(i, j + 1, dist + 1);
    };

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == 1)
            {
                grid[i][j] = 0;
                dfs(i, j, 1);
            }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] > 1)
                mx = max(mx, grid[i][j] - 1);

    return mx;
}