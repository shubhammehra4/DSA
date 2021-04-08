#include <bits/stdc++.h>
using namespace std;

int trailingZeroes (int a)
{
    int count = 0;

    for (int i = 5; a / i >= 1; i *= 5)
        count += a / i;

    return count;
}

int main()
{
    int n = 20;
    cout << trailingZeroes (n);
    return 0;
}