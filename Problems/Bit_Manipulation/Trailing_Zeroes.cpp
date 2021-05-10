#include <bits/stdc++.h>
using namespace std;

int trailingZeroBits(int A)
{
    int res = 0;
    while ((A & 1) == 0)
    {
        res++;
        A = A >> 1;
    }

    return res;
}

int main()
{
    cout << trailingZeroBits(140);
    return 0;
}