#include <bits/stdc++.h>
using namespace std;

// STL
int hammingWeight(uint32_t n)
{
    return __builtin_popcount(n);
}

// Custom
// Using Brian Kernighan’s algorithm
int hammingWeight(uint32_t n)
{
    int count = 0;

    while (n)
    {
        n &= (n - 1); // clear the least significant bit set
        count++;
    }

    return count;
}

// Naive solution
int hammingWeight(uint32_t n)
{
    int count = 0;

    while (n)
    {
        count += (n & 1); // check last bit
        n >>= 1;
    }

    return count;
}

int main()
{
    return 0;
}