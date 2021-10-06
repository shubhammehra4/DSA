#include <bits/stdc++.h>
using namespace std;

/*
Concept:
    When we take xor of two numbers the bits with same numbers become zero and 
    with different numbers become 1
*/

// STL
int hammingDistance(int x, int y)
{
    return __builtin_popcount(x ^ y);
}

// CUSTOM
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

int main()
{
    return 0;
}