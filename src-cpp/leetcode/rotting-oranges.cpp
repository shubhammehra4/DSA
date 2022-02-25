#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    int freshCnt = 0;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == 2)
                q.push({r, c});
            else if (grid[r][c] == 1)
                freshCnt++;
        }
    }

    if (freshCnt == 0)
        return 0;

    int time = 0;
    vector<int> directions({-1, 0, 1, 0, -1});
    auto isValidCoordinates = [&m, &n](int r, int c) -> bool
    {
        return r >= 0 && r < m && c >= 0 && c < n;
    };

    while (!q.empty())
    {
        int levelSize = q.size();
        time++;

        while (levelSize--)
        {
            auto coordinates = q.front();
            q.pop();
            auto x = coordinates.first;
            auto y = coordinates.second;

            for (int i = 0; i < 4; i++)
            {
                int r = x + directions[i];
                int c = y + directions[i + 1];
                if (isValidCoordinates(r, c) && grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    freshCnt--;
                    q.push({r, c});
                }
            }
        }
    }

    if (freshCnt != 0)
        return -1;

    return time == 0 ? 0 : time - 1;
}