#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
Consider a money system consisting of n coins. Each coin has a positive 
integer value. Your task is to calculate the number of distinct ways you 
can produce a money sum x using the available coins.

Recurrence Relation
{2,3,5}

f(9) = f(9-2) + f(9-3) + f(9-5) -> f(7) + f(6) + f(4)

{x1,x2,x3,...}
f(n) = f(n-x1) + f(n-x2) + f(n-x3) ...
*/

int dpCombinations(int x, vector<int> coins)
{
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (auto j : coins)
        {
            if (j > i)
                continue;
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }

    return dp[x] % mod;
}

int main()
{

    int n, x;
    cin >> n >> x;
    vector<int> coins;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        coins.push_back(temp);
    }

    cout << dpCombinations(x, coins);
    return 0;
}