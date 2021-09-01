/*
You are given an m x n binary matrix grid. An island is a group of 1's 
(representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0
*/

#include <bits/stdc++.h>
using namespace std;

// Island Area DFS
int IslandA(vector<vector<int>> &g, int i, int j)
{
    if (i >= 0 && i < g.size() && j >= 0 && j < g[0].size() && g[i][j] == 1)
    {
        g[i][j] = 2; // Visited
        // 4-directions
        return 1 +
               IslandA(g, i + 1, j) + IslandA(g, i - 1, j) +
               IslandA(g, i, j - 1) + IslandA(g, i, j + 1);
    }
    return 0;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int max_area = 0;

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 1)
                max_area = max(max_area, IslandA(grid, i, j));

    return max_area;
}

// ------------------------------------------------------------------------

// Island Area BFS
int IslandABFS(vector<vector<int>> &g, int row, int col)
{
    int m = g.size(), n = g[0].size(), area = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    g[row][col] = 2; // Visited
    vector<int> dir({-1, 0, 1, 0, -1});
    while (!q.empty())
    {
        int z = q.front().first, x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int r = z + dir[i], c = x + dir[i + 1];
            if (r >= 0 && r < m && c >= 0 && c < n && g[r][c] == 1)
            {
                g[r][c] = 2;
                area++;
                q.push({r, c});
            }
        }
    }
    return area;
}

int maxAreaOfIsland2(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size(), ans = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                ans = max(ans, IslandABFS(grid, i, j));
    return ans;
}

int main()
{
    return 0;
}