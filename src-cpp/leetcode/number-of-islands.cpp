#include <bits/stdc++.h>
using namespace std;

// bfs
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    const int dir[5] = {-1, 0, 1, 0, -1};

    int island = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                island++;
                grid[i][j] = '0';
                queue<pair<int, int>> q;
                q.push({i, j});

                while (!q.empty())
                {
                    auto [i, j] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++)
                    {
                        int x = i + dir[d];
                        int y = j + dir[d + 1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1')
                        {
                            grid[x][y] = '0';
                            q.push({x, y});
                        }
                    }
                }
            }
        }
    }

    return island;
}