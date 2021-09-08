#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
You know that an array has n integers between 1 and m, and the absolute difference 
between two adjacent values is at most 1.

Given a description of the array where some values may be unknown, your task is to 
count the number of arrays that match the description.

Reccurrence Relation
i - index , j - range (0,m)
f(j,i) => 
    if (arr[i] != 0)
        f(j, i-1) + f(j-1,i-1) + f(j-1,i+1)
    else
        f(arr[i]-1, i-1) + f(arr[i], i-1) + f(arr[i]+1, i-1)
*/

int dpArrayWays(int m, vector<int> arr)
{
    long long n = arr.size();
    vector<vector<long long>> dp(m + 1, vector<long long>(n, 0));

    if (arr[0] != 0)
        dp[arr[0]][0] = 1;
    else
    {
        for (int j = 1; j <= m; j++)
            dp[j][0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            dp[arr[i]][i] = ((arr[i] - 1 > 0 ? dp[arr[i] - 1][i - 1] : 0) +
                             dp[arr[i]][i - 1] +
                             (arr[i] + 1 <= m ? dp[arr[i] + 1][i - 1] : 0)) %
                            mod;
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
                if (j < m)
                    dp[j][i] += dp[j + 1][i - 1];

                dp[j][i] %= mod;
            }
        }
    }

    if (arr[n - 1] != 0)
        return dp[arr[n - 1]][n - 1] % mod;

    long long res = 0;
    for (int j = 1; j <= m; j++)
        res = (res + dp[j][n - 1]) % mod;

    return res % mod;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);

    for (auto &i : arr)
        cin >> i;

    cout << dpArrayWays(m, arr);
    return 0;
}