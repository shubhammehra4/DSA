#include <bits/stdc++.h>
using namespace std;

/**
 * DFS in reversed direction
 * going from border cells to higher cells
 */
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<bool>> pacific(m, vector<bool>(n));
    vector<vector<bool>> atlantic(m, vector<bool>(n));

    vector<int> direction = {0, 1, 0, -1, 0};

    auto outOfBounds = [&m, &n](int row, int col) -> bool
    {
        return row < 0 || col < 0 || row > m - 1 || col > n - 1;
    };

    function<void(int, int, vector<vector<bool>> &)> dfs =
        [&heights, &direction, &outOfBounds, &dfs](int row, int col, vector<vector<bool>> &visited) -> void
    {
        visited[row][col] = true;

        for (int d = 0; d < 4; d++)
        {
            int r = row + direction[d];
            int c = col + direction[d + 1];

            if (!outOfBounds(r, c) && !visited[r][c] && heights[r][c] >= heights[row][col])
                dfs(r, c, visited);
        }
    };

    for (int i = 0; i < m; i++)
    {
        dfs(i, 0, pacific);      // left border
        dfs(i, n - 1, atlantic); // right border
    }

    for (int j = 0; j < n; j++)
    {
        dfs(0, j, pacific);      // top border
        dfs(m - 1, j, atlantic); // bottom border
    }

    vector<vector<int>> res;
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (pacific[r][c] && atlantic[r][c])
                res.push_back({r, c});
        }
    }

    return res;
}

/**
 * Space Optimised
 * Bit Masking
 */
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<short>> visited(m, vector<short>(n, 0));
    vector<int> direction = {0, 1, 0, -1, 0};

    auto outOfBounds = [&m, &n](int row, int col) -> bool
    {
        return row < 0 || col < 0 || row > m - 1 || col > n - 1;
    };

    function<void(int, int, short)> dfs =
        [&heights, &visited, &direction, &outOfBounds, &dfs](int row, int col, short mask) -> void
    {
        visited[row][col] |= mask;

        for (int d = 0; d < 4; d++)
        {
            int r = row + direction[d];
            int c = col + direction[d + 1];

            if (!outOfBounds(r, c) && (visited[r][c] & mask) != mask && heights[r][c] >= heights[row][col])
                dfs(r, c, mask);
        }
    };

    short pacificMask = 1;
    short atlanticMask = 2;

    for (int i = 0; i < m; i++)
    {
        dfs(i, 0, pacificMask);      // left border
        dfs(i, n - 1, atlanticMask); // right border
    }

    for (int j = 0; j < n; j++)
    {
        dfs(0, j, pacificMask);      // top border
        dfs(m - 1, j, atlanticMask); // bottom border
    }

    vector<vector<int>> res;
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if ((visited[r][c] & pacificMask) && (visited[r][c] & atlanticMask))
                res.push_back({r, c});
        }
    }

    return res;
}