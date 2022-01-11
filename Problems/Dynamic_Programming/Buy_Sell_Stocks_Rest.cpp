#include <bits/stdc++.h>
using namespace std;

// States
// S0 - (rest,buy)
// S1 - (rest,sell)
// S2 - (rest)
int maxProfit(vector<int> &prices)
{
    if (prices.size() <= 1)
        return 0;

    int n = prices.size();
    vector<int> buy(n, 0), sell(n, 0), rest(n, 0);
    sell[0] = -prices[0];
    buy[0] = 0;
    rest[0] = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        buy[i] = max(buy[i - 1], rest[i - 1]);
        sell[i] = max(sell[i - 1], buy[i - 1] - prices[i]);
        rest[i] = sell[i - 1] + prices[i];
    }

    return max(buy[n - 1], rest[n - 1]);
}
// [1,2,3,0,2]

// O(1) space
int maxProfit2(vector<int> &prices)
{
    if (prices.size() <= 1)
        return 0;

    int buy = INT_MIN, sell = 0, prev_sell = 0, prev_buy;
    for (int price : prices)
    {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}

int main()
{
    return 0;
}