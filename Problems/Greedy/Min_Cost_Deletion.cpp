#include <bits/stdc++.h>
using namespace std;

// if we have repeated characters, we need to remove all of them except one -
// the "most expensive" character to remove.
int minCost(string s, vector<int> &cost)
{
    int res = cost[0], max_cost = cost[0];

    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[i - 1])
        {
            res -= max_cost;
            max_cost = 0;
        }
        res += cost[i];
        max_cost = max(max_cost, cost[i]);
    }

    return res - max_cost;
}

// Stack Solution
int minCost(string s, vector<int> &cost)
{
    if (s.empty())
        return 0;

    int minCost = 0;
    stack<int> stk; // stack to maintain indices parsed till now
    stk.push(0);
    for (int i = 1; i < s.size(); ++i)
    {
        if (!stk.empty() && s[stk.top()] == s[i])
        {
            if (cost[stk.top()] <= cost[i])
            {
                minCost += cost[stk.top()];
                stk.pop();
                stk.push(i);
            }
            else
                minCost += cost[i];
        }
        else
            stk.push(i);
    }

    return minCost;
}

int main()
{
    return 0;
}