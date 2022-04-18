#include <bits/stdc++.h>
using namespace std;

// further optimisation
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> cur(m, 0);
    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i][0] == 0)
            cur[i] = 1;
        else
            break;
    }

    for (int j = 1; j < n; j++)
    {
        bool flag = false;
        if (obstacleGrid[0][j] == 1)
            cur[0] = 0;
        else
            flag = true;

        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][j] == 0)
            {
                cur[i] += cur[i - 1];
                if (cur[i])
                    flag = true;
            }
            else
                cur[i] = 0;
        }

        if (flag == false)
            return 0;
    }

    return cur[m - 1];
}

// space optimised
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> pre(m, 0);
    vector<int> cur(m, 0);

    for (int i = 0; i < m; i++)
        if (obstacleGrid[i][0] == 0)
            pre[i] = 1;
        else
            break;

    for (int j = 1; j < n; j++)
    {
        bool flag = false;
        if (obstacleGrid[0][j] == 0)
        {
            cur[0] = pre[0];
            if (cur[0])
                flag = true;
        }
        else
            cur[0] = 0;

        for (int i = 1; i < m; i++)
        {
            if (obstacleGrid[i][j] == 0)
            {
                cur[i] = cur[i - 1] + pre[i];
                if (cur[i])
                    flag = true;
            }
            else
                cur[i] = 0;
        }

        if (flag == false)
            return 0;

        swap(pre, cur);
    }

    return pre[m - 1];
}

// dp
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][1] = 1; // src

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (obstacleGrid[i - 1][j - 1] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m][n];
}

// alter dp
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
        if (obstacleGrid[0][j] == 0)
            dp[0][j] = 1;
        else
            break;

    for (int i = 0; i < m; i++)
        if (obstacleGrid[i][0] == 0)
            dp[i][0] = 1;
        else
            break;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (obstacleGrid[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m - 1][n - 1];
}