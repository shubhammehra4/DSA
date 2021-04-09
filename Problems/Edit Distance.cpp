// Levenshtien Distance
// Space Complexity used is O(mn) can be reduced to O(n) by only storing 2 columns
#include <bits/stdc++.h>
using namespace std;

int editWithoutReplacement (string a, string b) // only insert & delete existing words
{
    int m = a.length();
    int n = b.length();
    vector<vector<int>> ed (m + 1, vector<int> (n + 1, 0) );

    for (int c = n - 1; c >= 0; c--)
    {
        for (int r = m - 1; r >= 0; r--)
        {
            if (a[r] == b[c])
                ed[r][c] = 1 + ed[r + 1][c + 1];
            else
                ed[r][c] = max (ed[r][c + 1], ed[r + 1][c]);
        }
    }

    return ed[0][0];
}

int editWithReplacement (string a, string b)
{
    int m = a.length();
    int n = b.length();
    vector<vector<int>> ed (m + 1, vector<int> (n + 1, 0) );

    for (int r = 0; r < m + 1; r++) ed[r][n] = m - r;

    for (int c = 0; c < n + 1; c++) ed[m][c] = n - c;

    for (int c = n - 1; c >= 0; c--)
    {
        for (int r = m - 1; r >= 0; r--)
        {
            if (a[r] == b[c])
                ed[r][c] = ed[r + 1][c + 1];
            else
                ed[r][c] = 1 + min (min (ed[r + 1][c + 1], ed[r][c + 1]), ed[r + 1][c]);
        }
    }

    return ed[0][0];
}


int main()
{
    cout << editWithReplacement ("secret", "bisect");
    return 0;
}