#include <bits/stdc++.h>
using namespace std;

// dynamic programming !
int lenLongestFibSubseq(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> m;
    int res = 0;
    int dp[n][n];

    for (int j = 0; j < n; ++j)
    {
        m[arr[j]] = j;
        for (int i = 0; i < j; ++i)
        {
            int k = m.find(arr[j] - arr[i]) == m.end() ? -1 : m[arr[j] - arr[i]];
            dp[i][j] = (arr[j] - arr[i] < arr[i] && k >= 0) ? dp[k][i] + 1 : 2;
            res = max(res, dp[i][j]);
        }
    }
    return res > 2 ? res : 0;
}

int lenLongestFibSubseq(vector<int> &arr)
{
    int n = arr.size();
    int res = 0;
    unordered_set<int> st(begin(arr), end(arr));

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            int x = arr[i], y = arr[j];
            int length = 2;

            while (st.find(x + y) != st.end())
            {
                int z = x + y;
                x = y;
                y = z;
                length++;
            }

            res = max(res, length);
        }

    return res > 2 ? res : 0;
}