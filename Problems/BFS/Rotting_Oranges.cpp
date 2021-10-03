#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    int oranges = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                oranges++;
            else if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    if (oranges == 0)
        return 0;

    vector<int> dir = {-1, 0, 1, 0, -1};
    int res = 0;

    while (!q.empty())
    {
        if (oranges == 0)
            return res;

        res++;
        int size = q.size();
        while (size--)
        {
            auto curr = q.front();
            int x = curr.first, y = curr.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = x + dir[i];
                int c = y + dir[i + 1];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                {
                    grid[r][c] = 2;
                    q.push({r, c});
                    oranges--;
                }
            }
        }
    }

    return -1;
}

int main()
{
    return 0;
}