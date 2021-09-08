#include <bits/stdc++.h>
using namespace std;

/*
You have n coins with certain values. Your task is to find all money sums 
you can create using these coins.

It is possible to make x with the first i coins, if either it was possible 
with the first i-1 coins, or we chose the i'th coin, and it was possible to make 
x — <value of i'th coin> using the first i-1 coins.
*/

int main()
{
    int n;
    cin >> n;
    int max_sum = n * 1000;
    vector<int> coins(n);

    for (int &v : coins)
        cin >> v;

    vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= max_sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - coins[i - 1];
            if (left >= 0 && dp[i - 1][left])
            {
                dp[i][j] = true;
            }
        }
    }

    vector<int> possible;
    for (int j = 1; j <= max_sum; j++)
    {
        if (dp[n][j])
            possible.push_back(j);
    }

    cout << possible.size() << endl;
    for (int v : possible)
    {
        cout << v << ' ';
    }
    cout << endl;
}