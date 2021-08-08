#include <bits/stdc++.h>
using namespace std;

int minCut(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
        dp[i][i] = true; // Single Characters

    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1])
            dp[i][i + 1] = true; // consecutive Characters

    // Now traverse for every substring of size>=2 whether they are palindrome or not
    // For this checking we can see that if two end elements of a string is same
    // and intermediate string is palindrome then the whloe string is palindrome alse.

    for (int i = n - 3; i >= 0; i--) // (j - i) >= 2
    {
        for (int j = n - 1; j >= 2; j--)
        {
            if (s[i] == s[j] && dp[i + 1][j - 1] == true)
                dp[i][j] = true;
        }
    }

    vector<int> cuts(n, 0);
    int temp;

    for (int i = 0; i < n; i++)
    {
        temp = INT_MAX;

        // If the substring is palindrome from the start then no cuts are required.
        if (dp[0][i] == true)
            cuts[i] = 0;
        // Else check every substring with same logic and try to figure out the minimum number of cuts which is needed
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j + 1][i] == true && temp > cuts[j] + 1)
                    temp = cuts[j] + 1;
            }

            cuts[i] = temp;
        }
    }

    return cuts[n - 1];
}

int main()
{

    return 0;
}