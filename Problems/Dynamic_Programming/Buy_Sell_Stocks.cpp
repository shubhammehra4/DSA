/*
You want to maximize your profit by choosing a single day to buy 
one stock and choosing a different day in the future to sell that stock.
*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for (auto price : prices)
    {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

int main()
{
    return 0;
}