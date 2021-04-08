#include <bits/stdc++.h>
using namespace std;

int getMinCostConversion (string s1, string s2 )
{
    int n = s1.length(), m = s2.length();
    int dp[n][m];

    for (int i = 0 ; i <= n; i++)
    {
        for (int j = 0; j <= m; j++ )
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min (dp[i - 1][j], min (dp[i][j - 1], dp[i - 1][j - 1]) );
        }
    }

    return dp[n][m];
}

int main()
{
    string str1 = "march";
    string str2 = "cart";
    getMinCostConversion (str1, str2);
    return 0;
}