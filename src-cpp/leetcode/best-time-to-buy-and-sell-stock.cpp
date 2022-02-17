#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int minPrice = INT_MAX;

    for (auto price : prices)
    {
        minPrice = min(minPrice, price);
        profit = max(profit, price - minPrice);
    }

    return profit;
}

// Alter
int maxProfit(vector<int> &prices)
{
    int maxProfitSoFar = 0;
    int currProfit = 0;

    for (int i = 1; i < prices.size(); i += 1)
    {
        currProfit = max(0, currProfit + (prices[i] - prices[i - 1]));
        maxProfitSoFar = max(maxProfitSoFar, currProfit);
    }

    return maxProfitSoFar;
}