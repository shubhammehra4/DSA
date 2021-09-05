#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
Consider an n×n grid whose squares may have traps. It is not allowed to move 
to a square with a trap.

Your task is to calculate the number of paths from the upper-left square to the 
lower-right square. You can only move right or down.

Recurrence Relation
    (i,j) -> (n,m)
    f(i,j,n,m) = f(i-1,j,n,m) + f(i,j-1,n,m)
*/

int dpGridPaths(int n, vector<vector<int>> grid)
{
    if (grid[n - 1][n - 1] == 0) // destination blocked
        return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n - 1][n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) // last column
        dp[i][n - 1] = grid[i][n - 1] == 0 ? 0 : (dp[i + 1][n - 1] + dp[i][n - 1]);

    for (int i = n - 2; i >= 0; i--) // last row
        dp[n - 1][i] = grid[n - 1][i] == 0 ? 0 : (dp[n - 1][i + 1] + dp[n - 1][i]);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (grid[i][j] == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i + 1][j] % mod + dp[i][j + 1] % mod) % mod;
        }
    }

    return dp[0][0];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    char c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            grid[i][j] = c == '.' ? 1 : 0;
        }

    cout << dpGridPaths(n, grid);
    return 0;
}