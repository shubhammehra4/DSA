#include <bits/stdc++.h>
using namespace std;

// binary-search
bool judgeSquareSum(int c)
{
    function<bool(long, long, int &)> binarySearch = [&binarySearch](long start, long end, int &n) -> bool
    {
        if (start > end)
            return false;

        long mid = start + (end - start) / 2;

        if (mid * mid == n)
            return true;

        if (mid * mid > n)
            return binarySearch(start, mid - 1, n);

        return binarySearch(mid + 1, end, n);
    };

    for (long a = 0; a * a <= c; a++)
    {
        int b = c - (int)(a * a);

        if (binarySearch(0, b, b)) // square root exists
            return true;
    }

    return false;
}

// optimised
bool judgeSquareSum(int c)
{
    for (long a = 0; a * a <= c; a++)
    {
        double b = sqrt(c - (a * a));

        if (b == (int)b)
            return true;
    }

    return false;
}

// optimised alter
bool judgeSquareSum(int c)
{
    for (long a = 0; a * a <= c; a++)
    {
        int b = c - (int)(a * a);
        int i = 1, sum = 0;

        while (sum < b)
        {
            sum += i;
            i += 2;
        }

        // mathematical property:- sum of first n odd nums = square of nth +ve int
        if (sum == b)
            return true;
    }

    return false;
}

// brute-force
bool judgeSquareSum(int c)
{
    for (long a = 0; a * a <= c; a++)
    {
        for (long b = 0; b * b <= c; b++)
        {
            if (a * a + b * b == c)
                return true;
        }
    }

    return false;
}
