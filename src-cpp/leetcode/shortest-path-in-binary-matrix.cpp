#include <bits/stdc++.h>
using namespace std;

// bfs
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if (grid.empty() || grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
        return -1;

    vector<int> dir{0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
    int steps = 0;
    queue<pair<int, int>> q;

    q.push({0, 0});
    grid[0][0] = 1;
    while (!q.empty())
    {
        steps++;
        int levelSize = q.size();
        while (levelSize--)
        {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return steps;

            for (int i = 0; i < 9; i++)
            {
                int row = r + dir[i];
                int col = c + dir[i + 1];

                if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 0)
                {
                    q.push({row, col});
                    grid[row][col] = 1;
                }
            }
        }
    }

    return -1;
}

// bfs (direction alternative)
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if (grid.empty() || grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
        return -1;

    int steps = 0;
    queue<pair<int, int>> q;

    q.push({0, 0});
    grid[0][0] = 1;
    while (!q.empty())
    {
        steps++;
        int levelSize = q.size();
        while (levelSize--)
        {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return steps;

            int rowLimit = min(r + 1, m - 1);
            int colLimit = min(c + 1, n - 1);
            for (int row = max(0, r - 1); row <= rowLimit; row++)
            {
                for (int col = max(0, c - 1); col <= colLimit; col++)
                {
                    if (grid[row][col] == 0)
                    {
                        q.push({row, col});
                        grid[row][col] = 1;
                    }
                }
            }
        }
    }

    return -1;
}