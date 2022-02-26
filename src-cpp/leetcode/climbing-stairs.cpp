#include <bits/stdc++.h>
using namespace std;

// ptc
int climbStairs(int n, int a = 1, int b = 2)
{
    if (n == 1)
        return a;
    if (n == 2)
        return b;

    return climbStairs(n - 1, b, a + b);
}

// iterative
int climbStairs(int n)
{
    int a = 1;
    int b = 1;

    for (int i = 2; i <= n; i++)
    {
        int t = b;
        b = a + b;
        a = t;
    }

    return b;
}