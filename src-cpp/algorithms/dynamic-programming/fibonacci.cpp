#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1;
    int tmp;

    for (int i = 2; i <= n; i++)
    {
        tmp = b;
        b = a + b;
        a = tmp;
    }

    return b;
}

int fib(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;

    return fib(n - 1, b, a + b);
}