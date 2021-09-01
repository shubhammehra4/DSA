#include <bits/stdc++.h>
using namespace std;
// DP
int helper(string x, string y)
{
    int m = x.size();
    int n = y.size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

bool isSubsequence(string smaller, string larger)
{
    if (helper(smaller, larger) == smaller.size())
        return true;

    return false;
}
// Twp Pointer
bool isSubsequence2(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    return i == m ? 1 : 0;
}

int main()
{
    return 0;
}