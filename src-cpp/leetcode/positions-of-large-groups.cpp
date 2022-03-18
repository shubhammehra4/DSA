#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> largeGroupPositions(string s)
{
    int n = s.size();
    vector<vector<int>> res;

    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == s[i + 1])
        {
            int j = i;
            while (j + 1 < n && s[j + 1] == s[i])
                j++;

            if (j - i >= 2)
                res.push_back({i, j});

            i = j;
        }
    }

    return res;
}