#include <bits/stdc++.h>
using namespace std;

// monotonic stack
vector<int> finalPrices(vector<int> &prices)
{
    stack<int> st;
    vector<int> res(prices);

    for (int i = 0; i < prices.size(); i++)
    {
        while (!st.empty() && prices[i] <= prices[st.top()])
        {
            res[st.top()] -= prices[i];
            st.pop();
        }

        st.push(i);
    }

    return res;
}

// brute-force
vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    vector<int> res;

    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;

        while (j < n - 1 && prices[i] < prices[j])
            j++;

        if (prices[j] <= prices[i])
            res.push_back(prices[i] - prices[j]);
        else
            res.push_back(prices[i]);
    }

    res.push_back(prices.back());

    return res;
}