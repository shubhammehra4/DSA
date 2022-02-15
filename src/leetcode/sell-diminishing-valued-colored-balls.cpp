#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &inventory, int orders)
{
    long res = 0, colors = 1;
    sort(begin(inventory), end(inventory));

    for (int i = inventory.size() - 1; i >= 0 && orders > 0; --i, ++colors)
    {
        long cur = inventory[i], prev = i > 0 ? inventory[i - 1] : 0;

        long rounds = min(orders / colors, cur - prev);

        orders -= rounds * colors;
        // pre-requesite to know the formula for greedy approach
        res = (res + (cur * (cur + 1) - (cur - rounds) * (cur - rounds + 1)) / 2 * colors) % 1000000007;
        if (cur - prev > rounds)
        {
            res = (res + orders * (cur - rounds)) % 1000000007;
            break;
        }
    }

    return res;
}

int maxProfitTLE(vector<int> &inventory, int orders)
{
    priority_queue<int> pq(begin(inventory), end(inventory));

    int profit = 0;
    while (orders--)
    {
        auto ball = pq.top();
        pq.pop();

        profit += ball;
        pq.push(ball - 1);
    }

    return profit;
}
