#include <bits/stdc++.h>
using namespace std;

// optimised binary-search
int mySqrt(int x)
{
    if (x < 2)
        return x;

    int l = 1, r = x;
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (x / mid >= mid)
            l = mid + 1;
        else
            r = mid;
    }

    return r - 1;
}

// binary-search
int mySqrt(int x)
{
    if (x == 0)
        return 0;

    int l = 1, r = INT_MAX;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (mid > x / mid) // divide instead of multiplying to avoid integer overflow
            r = mid - 1;
        else if ((mid + 1) > x / (mid + 1))
            return mid;
        else
            l = mid + 1;
    }

    return -1;
}