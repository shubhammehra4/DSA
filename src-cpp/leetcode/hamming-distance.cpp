#include <bits/stdc++.h>
using namespace std;

// XOR + stl
int hammingDistance(int x, int y)
{
    return __builtin_popcount(x ^ y);
}

// XOR
int hammingDistance(int x, int y)
{
    int n = x ^ y;
    int count = 0;

    while (n)
    {
        n &= (n - 1);
        count++;
    }

    return count;
}
