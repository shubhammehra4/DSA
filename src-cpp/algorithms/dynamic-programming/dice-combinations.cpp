#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
Your task is to count the number of ways to construct sum n by throwing
a dice one or more times. Each throw produces an outcome between 1 and 6.

Recurrence Relation
f(0) = 1
f(1) = 1
f(2) = 2
f(3) = 4
f(4) = 8

f(n)  = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)
*/

int diceSum(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < min(i + 1, 7); j++)
            dp[i] = (dp[i] + dp[i - j]) % mod;
    }

    return dp[n] % mod;
}

int main()
{
    int n;
    cin >> n;
    cout << diceSum(n);
    return 0;
}