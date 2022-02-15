#include <bits/stdc++.h>
using namespace std;

// Adding values from local maximas and minimas
int maxProfit(vector<int> &prices)
{
    int profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i - 1] < prices[i])
            profit += prices[i] - prices[i - 1];
    }

    return profit;
}

// Alternative
int maxProfit(vector<int> &prices)
{
    int n = prices.size() - 1;
    int buy, sell;
    int profit = 0;

    int day = 0;
    while (day < n)
    {
        while (day < n && prices[day + 1] <= prices[day])
            day++;
        buy = prices[day];

        while (day < n && prices[day + 1] > prices[day])
            day++;
        sell = prices[day];

        profit += sell - buy;
    }

    return profit;
}