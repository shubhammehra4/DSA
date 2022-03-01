#include <bits/stdc++.h>
using namespace std;

/**
 *  Prev Col State
 *
    0    1    2    3    4    5    6    7

    0    1    0    1    0    1    0    1
    0    0    1    1    0    0    1    1
    0    0    0    0    1    1    1    1

 * State 2 & 5 don't appear if 2*1 dominos are used
 */

int tileDominos(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(8, 0));
    dp[0][7] = 1; // first column is fully empty so it's prev col will be full(state 7)

    for (int i = 1; i < n + 1; i++)
    {
        dp[i][0] += dp[i - 1][7];

        dp[i][1] += dp[i - 1][6];

        // dp[i][2] += dp[i - 1][5];

        dp[i][3] += dp[i - 1][7]; // add vertical domino from top
        dp[i][3] += dp[i - 1][4]; // 2 horizontal stacked dominos from top

        dp[i][4] += dp[i - 1][3];

        // dp[i][5] += dp[i - 1][2];

        dp[i][6] += dp[i - 1][7]; // add vertical domino from bottom
        dp[i][6] += dp[i - 1][1]; // 2 horizontal stacked dominos from bottom

        dp[i][7] += dp[i - 1][6]; // add 2 dominos in rotated L shape
        dp[i][7] += dp[i - 1][3]; // add 2 dominos in rotated L shape
        dp[i][7] += dp[i - 1][0]; // 3 horizontal stacked dominos
    }

    return dp[n][7];
}