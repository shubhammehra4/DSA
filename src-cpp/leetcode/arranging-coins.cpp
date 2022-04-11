#include <bits/stdc++.h>
using namespace std;

int arrangeCoins(int n)
{
    long long l = 0, r = n;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        long long rows = mid * (mid + 1) / 2;

        if (rows <= n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return r;
}