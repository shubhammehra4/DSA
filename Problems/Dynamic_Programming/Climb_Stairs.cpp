/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many 
distinct ways can you climb to the top?
*/
#include <bits/stdc++.h>
using namespace std;

// Fibonacci Pattern
int climbStairs(int n)
{
    if (n < 3)
        return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

/*
You are given an integer array cost where cost[i] is the cost of ith step 
on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++)
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);

    return min(dp[n - 1], dp[n - 2]);
}

// Space optimized
int minCostClimbingStairs2(vector<int> &cost)
{
    int n = cost.size();
    int first = cost[0];
    int second = cost[1];
    if (n <= 2)
        return min(first, second);

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(first, second);
        first = second;
        second = curr;
    }
    return min(first, second);
}

int main()
{
    return 0;
}