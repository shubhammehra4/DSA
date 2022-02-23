#include <bits/stdc++.h>
using namespace std;

// dfs
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int maxArea = 0;

    function<int(int, int)> dfsUtil = [&grid, &m, &n, &dfsUtil](int r, int c) -> int
    {
        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
        {
            grid[r][c] = -1; // visited
            return 1 + dfsUtil(r + 1, c) + dfsUtil(r - 1, c) + dfsUtil(r, c + 1) + dfsUtil(r, c - 1);
        }

        return 0;
    };

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
            if (grid[r][c] == 1)
                maxArea = max(maxArea, dfsUtil(r, c));
    }

    return maxArea;
}

// bfs
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int maxArea = 0;

    function<int(int, int)> bfsUtil = [&grid, &m, &n](int r, int c) -> int
    {
        int area = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = -1;

        vector<int> dir({-1, 0, 1, 0, -1});

        while (!q.empty())
        {
            auto box = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = box.first + dir[i], c = box.second + dir[i + 1];

                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                {
                    grid[r][c] = -1;
                    area++;
                    q.push({r, c});
                }
            }
        }

        return area;
    };

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
            if (grid[r][c] == 1)
                maxArea = max(maxArea, bfsUtil(r, c));
    }

    return maxArea;
}
