#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int cooldown = 0;
    int selling = 0;
    int buying = -prices[0];

    for (auto &price : prices)
    {
        int prev = selling;
        selling = buying + price;
        buying = max(buying, cooldown - price);
        cooldown = max(cooldown, prev);
    }
    return max(selling, cooldown);
}

/**
 * s0 - ready to buy
 * s1 - ready to sell
 * s3 - rest
 */
int maxProfitStateSol(vector<int> &prices)
{
    int n = prices.size();
    if (n <= 1)
        return 0;

    vector<int> s0(n, 0);
    vector<int> s1(n, 0);
    vector<int> s2(n, 0);

    s1[0] = -prices[0];
    s0[0] = 0;
    s2[0] = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        s0[i] = max(s0[i - 1], s2[i - 1]);             // Stay at s0, or rest from s2
        s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]); // Stay at s1, or buy from s0
        s2[i] = s1[i - 1] + prices[i];                 // Only one way from s1
    }

    return max(s0[n - 1], s2[n - 1]);
}