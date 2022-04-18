#include <bits/stdc++.h>
using namespace std;

// further optimisation
int uniquePaths(int m, int n)
{
    vector<int> cur(n, 1);
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            cur[j] += cur[j - 1];

    return cur[n - 1];
}

// space-optimised dp
int uniquePaths(int m, int n)
{
    vector<int> pre(n, 1);
    vector<int> cur(n, 1);

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
            cur[j] = pre[j] + cur[j - 1];

        swap(pre, cur);
    }

    return pre[n - 1];
}

// dp
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));

    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    for (int i = 0; i < m; i++)
        dp[i][0] = 1;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m - 1][n - 1];
}