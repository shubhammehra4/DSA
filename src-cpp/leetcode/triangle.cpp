#include <bits/stdc++.h>
using namespace std;

// iterative
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> dp = triangle.back();

    for (int depth = n - 2; depth >= 0; depth--)
    {
        for (int i = 0; i <= depth; i++)
            dp[i] = triangle[depth][i] + min(dp[i], dp[i + 1]);
    }

    return dp[0];
}

// recursive
int minimumTotal(vector<vector<int>> &triangle, int depth = 0, int i = 0)
{
    int n = triangle.size();
    vector<vector<int>> memo(n);

    function<int(int, int)> minimumTotalUtil = [&n, &triangle, &memo, &minimumTotalUtil](int depth, int i) -> int
    {
        if (depth >= n)
            return 0;

        if (i >= depth + 1)
            return INT_MAX;

        if (i == 0)
            memo[depth] = vector<int>(depth + 1, -1);

        if (memo[depth][i] != -1)
            return memo[depth][i];

        memo[depth][i] = triangle[depth][i] + min(minimumTotalUtil(depth + 1, i), minimumTotalUtil(depth + 1, i + 1));

        return memo[depth][i];
    };

    return minimumTotalUtil(0, 0);
}