#include <bits/stdc++.h>
using namespace std;

/*
There is a list of n numbers and two players who move alternately. On each move, 
a player removes either the first or last number from the list, and their score 
increases by that number. Both players try to maximize their scores.

What is the maximum possible score for the first player when both players play optimally?

Reccurrence Relation
 * Both play optimally
j -> []
f(i,j) =  max(
            min (a[i] + f(i+1,j-1), 
                a[i] + f(i+2,j)),
            
            min(a[j] + f(i,j-2),
                a[j] + f(i+1,j-1))
        )

*/

long long dpRemovalGame(vector<long long> arr)
{
    long long n = arr.size();
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (long long len = 1; len <= n; len++)
    {
        for (long long i = 0; i + len <= n; i++)
        {
            long long j = i + len - 1;
            long long x, y, z;
            x = (i + 2 <= j) ? dp[i + 2][j] : 0;
            y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            z = (i <= j - 2) ? dp[i][j - 2] : 0;

            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    return dp[0][n - 1];
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> arr(n);

    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    cout << dpRemovalGame(arr);
    return 0;
}