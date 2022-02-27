#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    return __builtin_popcount(n) == 1;
}

// bit-manipulation
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    return ((n & (n - 1)) == 0);
}

// recursion
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    return n == 1 || (n % 2 == 0 && isPowerOfTwo(n / 2));
}

// remainder-divident
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;

    while (n % 2 == 0)
        n /= 2;

    return n == 1;
}