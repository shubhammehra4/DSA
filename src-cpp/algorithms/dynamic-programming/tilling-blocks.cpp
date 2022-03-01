#include <bits/stdc++.h>
using namespace std;

// general solution iterative
int tilingBlocks(int n, vector<int> &tiles)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    unordered_map<int, int> tileFreq; // size->count
    for (auto tile : tiles)
        tileFreq[tile]++;

    for (int i = 1; i <= n; i++)
    {
        for (auto t : tileFreq)
        {
            auto size = t.first;
            auto freq = t.second;

            if (size > i)
                continue;

            dp[i] += dp[i - size] * freq;
        }
    }

    return dp[n];
}

// general solution recursive
int tilingBlocks(int n, vector<int> &tiles)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;

    unordered_map<int, int> tileFreq; // size->count
    for (auto tile : tiles)
        tileFreq[tile]++;

    function<int(int)> solveUtil = [&dp, &tileFreq, &solveUtil](int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int count = 0;
        for (auto t : tileFreq)
            count += solveUtil(n - t.first) * t.second;

        dp[n] = count;
        return count;
    };

    return solveUtil(n);
}

// blocks of length 1 & 2
// naive
int tillingTwoBlocks(int n)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    return tillingTwoBlocks(n - 1) + tillingTwoBlocks(n - 2);
}