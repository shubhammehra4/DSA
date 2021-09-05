#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer n. On each step, you may subtract one of the 
digits from the number.

How many steps are required to make the number equal to 0?
Similar approach to minimizing coins
*/

int dpRemovingDigit(int n)
{
    vector<long long> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j /= 10)
        {
            if (j % 10 > i)
                continue;
            dp[i] = min(dp[i], 1 + dp[i - (j % 10)]);
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << dpRemovingDigit(n);
    return 0;
}