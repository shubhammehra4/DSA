#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid.front().size();

    vector<vector<int>> res(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int col = (j + k) % n;
            int countWrapArounds = (j + k) / n;
            int row = (i + countWrapArounds) % m;

            res[row][col] = grid[i][j];
        }
    }

    return res;
}