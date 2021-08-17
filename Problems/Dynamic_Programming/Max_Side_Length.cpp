#include <bits/stdc++.h>
using namespace std;

int maxSideLength(vector<vector<int>> &mat, int threshold)
{
    int m = mat.size();
    int n = mat[0].size();

    int least = min(m, n);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i + 1][j + 1] = mat[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
        }
    }

    int sum = 0;

    for (int k = least; k > 0; k--)
    {
        for (int i = k; i < m + 1; i++)
        {
            for (int j = k; j < n + 1; j++)
            {
                sum = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
                if (sum <= threshold)
                    return k;
            }
        }
    }

    return 0;
}

int main()
{

    return 0;
}