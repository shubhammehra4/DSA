#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num)
{
    if (num == 1)
        return true;

    long l = 0, r = num / 2;
    while (l <= r)
    {
        long mid = (l + r) >> 1;
        long sqmid = mid * mid;

        if (sqmid > num)
            r = mid - 1;
        else if (sqmid < num)
            l = mid + 1;
        else
            return true;
    }

    return false;
}

bool isPerfectSquare(int num)
{
    long r = num;
    while (r * r > num)
        r = (r + num / r) / 2;

    return r * r == num;
}