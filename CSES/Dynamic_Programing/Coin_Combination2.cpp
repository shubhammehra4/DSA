#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
Consider a money system consisting of n coins. Each coin has a positive 
integer value. Your task is to calculate the number of distinct ordered 
ways you can produce a money sum x using the available coins.

Recurrence Relation
for distinct values
calculate which sum can be made by an individual coin
*/

int dpCombinations2(int x, vector<int> coins)
{
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    for (auto j : coins)
    {
        for (int i = 1; i <= x; i++)
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

    cout << dpCombinations2(x, coins);
    return 0;
}