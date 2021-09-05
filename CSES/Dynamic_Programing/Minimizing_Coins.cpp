#include <bits/stdc++.h>
using namespace std;

/*
Consider a money system consisting of n coins. Each coin has a positive 
integer value. Your task is to produce a sum of money x using the available 
coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal 
solution is 5+5+1 which requires 3 coins.
*/

int dpMinimizingCoins(int x, vector<int> coins)
{
    vector<long long> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (auto j : coins)
        {
            if (j > i)
                continue;
            dp[i] = min(dp[i], 1 + dp[i - j]);
        }
    }

    return dp[x] == INT_MAX ? -1 : dp[x];
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

    cout << dpMinimizingCoins(x, coins);

    return 0;
}