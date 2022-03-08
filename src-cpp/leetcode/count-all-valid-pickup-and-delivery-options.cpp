#include <bits/stdc++.h>
using namespace std;

// iterative
const int MOD = 1e9 + 7;

int countOrders(int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));

    for (int unpicked = 0; unpicked <= n; unpicked++)
    {
        for (int undelivered = unpicked; undelivered <= n; undelivered++)
        {
            if (unpicked == 0 && undelivered == 0)
            {
                dp[unpicked][undelivered] = 1;
                continue;
            }

            if (unpicked > 0)
                dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];

            dp[unpicked][undelivered] %= MOD;

            if (undelivered > unpicked)
                dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];

            dp[unpicked][undelivered] %= MOD;
        }
    }

    return dp[n][n];
}

// recursive
int countOrders(int n)
{
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));
    const int MOD = 1e9 + 7;

    function<int(int, int)> totalWays =
        [&memo, &totalWays, &MOD](int unpicked, int undelivered) -> int
    {
        if (unpicked == 0 && undelivered == 0)
            return 1;

        if (unpicked < 0 || undelivered < 0 || undelivered < unpicked)
            return 0;

        if (memo[unpicked][undelivered])
            return memo[unpicked][undelivered];

        long ans = 0;

        // Count all choices of picking up an order.
        ans += unpicked * totalWays(unpicked - 1, undelivered);
        ans %= MOD;

        // Count all choices of delivering a picked order.
        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
        ans %= MOD;

        memo[unpicked][undelivered] = ans;
        return memo[unpicked][undelivered];
    };

    return totalWays(n, n);
}
