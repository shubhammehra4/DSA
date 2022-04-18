#include <bits/stdc++.h>
using namespace std;

// tail-recursion
int tribonacci(int n, int a = 0, int b = 1, int c = 1)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    if (n == 2)
        return c;

    return tribonacci(n - 1, b, c, a + b + c);
}

// iterative dp
int tribonacci(int n)
{
    int dp[3] = {0, 1, 1};

    for (int i = 3; i <= n; ++i)
        dp[i % 3] += dp[(i + 1) % 3] + dp[(i + 2) % 3];

    return dp[n % 3];
}

// iterative dp alter
int tribonacci(int n)
{
    if (n < 2)
        return n;

    int a = 0, b = 1, c = 1, d = a + b + c;
    while (n-- > 2)
    {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}
