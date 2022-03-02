#include <bits/stdc++.h>
using namespace std;

// dynamic-programming
bool isSubsequence(string s, string t)
{
    int n = s.size();
    int m = t.size();

    if (n == 0)
        return true;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n] == n;
}

// recursive
bool isSubsequence(string s, string t)
{
    function<bool(int, int)> isSubSeq = [&s, &t, &isSubSeq](int n, int m) -> bool
    {
        if (n == 0)
            return true;

        if (m == 0)
            return false;

        if (s[n - 1] == t[m - 1])
            return isSubSeq(n - 1, m - 1);

        return isSubSeq(n, m - 1);
    };

    return isSubSeq(s.size(), t.size());
}

// two-pointer
bool isSubsequence(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (t[j] == s[i])
            i++;

        j++;
    }

    return i == n;
}