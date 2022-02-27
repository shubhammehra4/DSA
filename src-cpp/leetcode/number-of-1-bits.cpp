#include <bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n)
{
    return __builtin_popcount(n);
}

int hammingWeight(uint32_t n)
{
    int setCount = 0;
    while (n > 0)
    {
        n &= (n - 1);
        setCount++;
    }

    return setCount;
}

int hammingWeight(uint32_t n)
{
    int setCount = 0;
    while (n > 0)
    {
        setCount += n % 2;
        n /= 2;
    }

    return setCount;
}