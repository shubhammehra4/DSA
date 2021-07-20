#include <bits/stdc++.h>
using namespace std;

int getMinCostConversion(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[n][m];
}

int main()
{
    string str1 = "march";
    string str2 = "cart";
    getMinCostConversion(str1, str2);
    return 0;
}

// for (int i = 0; i <= n; i++)
// {
//     for (int j = 0; j <= m; j++)
//     {
// if (i == 0)
//     dp[i][j] = j;
// else if (j == 0)
//     dp[i][j] = i;
//         else if (s1[i - 1] == s2[j - 1])
//             dp[i][j] = dp[i - 1][j - 1];
//         else
//             dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
//     }
// }