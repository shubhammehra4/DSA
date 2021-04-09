#include <bits/stdc++.h>
using namespace std;

int SubWord (string a, string b)
{
    int m = a.length();
    int n = b.length();
    vector<vector<int>> lcw (m + 1, vector<int> (n + 1, 0) );
    int maxLCW = 0;

    for (int c = n - 1; c >= 0; c--)
    {
        for (int r = m - 1; r >= 0; r--)
        {
            if (a[r] == b[c])
                lcw[r][c] = 1 + lcw[r + 1][c + 1];

            if (lcw[r][c] > maxLCW)
                maxLCW = lcw[r][c];
        }
    }

    return maxLCW;
}

int main()
{
    string a = "director";
    string b = "secretary";
    cout << SubWord ("secretary", "secret") << endl;
    cout << SubWord (a, b);
    return 0;
}