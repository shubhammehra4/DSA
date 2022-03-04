#include <bits/stdc++.h>
using namespace std;

// space-optimised
double champagneTower(int poured, int query_row, int query_glass)
{
    vector<double> dp(102);
    dp[0] = (double)poured;

    for (int row = 1; row <= query_row; row++)
    {
        for (int c = row; c >= 0; c--)
        {
            dp[c] = max(0.0, (dp[c] - 1.0) / 2.0);
            dp[c + 1] += dp[c];
        }
    }

    return min(dp[query_glass], 1.0);
}

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> dp(101, vector<double>(101));
    dp[0][0] = (double)poured;

    for (int r = 0; r < query_row; r++)
    {
        for (int c = 0; c <= min(r, query_glass); c++)
        {
            double excess = (dp[r][c] - 1.0) / 2.0;

            if (excess > 0)
            {
                dp[r + 1][c] += excess;
                dp[r + 1][c + 1] += excess;
            }
        }
    }

    return min(1.0, dp[query_row][query_glass]);
}