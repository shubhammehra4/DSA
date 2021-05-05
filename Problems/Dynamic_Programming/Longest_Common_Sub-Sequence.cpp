#include <bits/stdc++.h>
using namespace std;

// Space Complexity used is O(mn) can be reduced to O(n) by only storing 2 columns
int subSequence(string a, string b)
{
    int m = a.length();
    int n = b.length();
    if (m == 0 || n == 0)
        return 0;

    vector<vector<int>> lcs(m + 1, vector<int>(n + 1, 0));

    for (int c = n - 1; c >= 0; c--)
    {
        for (int r = m - 1; r >= 0; r--)
        {
            if (a[r] == b[c])
                lcs[r][c] = 1 + lcs[r + 1][c + 1];
            else
                lcs[r][c] = max(lcs[r][c + 1], lcs[r + 1][c]);
        }
    }

    return lcs[0][0];
}

int main()
{
    cout << subSequence("bisect", "secret") << endl;
    cout << subSequence("director", "secretary") << endl;
    return 0;
}