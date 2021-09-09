#include <bits/stdc++.h>
using namespace std;

/*
Given an a×b rectangle, your task is to cut it into squares. On each move you can 
select a rectangle and cut it into two rectangles in such a way that all side lengths 
remain integers. What is the minimum possible number of moves?

Greedy Approach 
    Take the longer side and cut it to form a square recursively
    It will not always give optimal no. of cuts

Dynamic Approach
    Try all possible ways to cut

    k->[1,j-1], l->[1,i-1]

    f(i,j) = min(
        min(
            f(i,j), 1 + f(i,k) + f(i,j-k)
        ),
        min(
            f(i,j), 1+ f(l,j) + f(i-l,j)
        )
    )
*/

int dpRectangleCuts(int n, int m)
{
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INT_MAX));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
            {
                for (int l = 1; l <= i - 1; l++) // Vertical Cuts
                    dp[i][j] = min(dp[i][j], 1 + dp[l][j] + dp[i - l][j]);

                for (int k = 1; k <= j - 1; k++) // Horizontal Cuts
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << dpRectangleCuts(a, b);
    return 0;
}