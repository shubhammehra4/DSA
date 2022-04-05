#include <bits/stdc++.h>
using namespace std;

// dfs
void dfs(vector<vector<char>> &board, const int &m, const int &n, int i, int j)
{
    if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O')
    {
        board[i][j] = '#';
        dfs(board, m, n, i - 1, j);
        dfs(board, m, n, i + 1, j);
        dfs(board, m, n, i, j - 1);
        dfs(board, m, n, i, j + 1);
    }
}
void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();

    // boundary columns
    for (int row = 0; row < m; row++)
    {
        if (board[row][0] == 'O')
            dfs(board, m, n, row, 0);

        if (board[row][n - 1] == 'O')
            dfs(board, m, n, row, n - 1);
    }

    // boundary rows
    for (int col = 0; col < n; col++)
    {
        if (board[0][col] == 'O')
            dfs(board, m, n, 0, col);

        if (board[m - 1][col] == 'O')
            dfs(board, m, n, m - 1, col);
    }

    for (auto &row : board)
    {
        for (auto &col : row)
        {
            if (col == 'O')
                col = 'X';
            else if (col == '#')
                col = 'O';
        }
    }
}