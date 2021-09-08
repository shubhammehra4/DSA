#include <bits/stdc++.h>
using namespace std;

/*
The edit distance between two strings is the minimum number of operations required 
to transform one string into the other.

The allowed operations are:
Add one character to the string.
Remove one character from the string.
Replace one character in the string.
For example, the edit distance between LOVE and MOVIE is 2, because you can first 
replace L with M, and then add I.

Reccurrence Relation

f(s1,s2,i,j) =>
    if(s1[i]==s2[j])
        f(s1,s2,i-1,j-1)
    else
        1 + min(f(s1,s2,i-1,j-1) + f(s1,s2,i-1,j) + f(s1,s2,i,j-1))
                   (replace)         (deletion)       (addition)
*/

int dpEditDistance(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
        }
    }

    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << dpEditDistance(s1, s2);
    return 0;
}