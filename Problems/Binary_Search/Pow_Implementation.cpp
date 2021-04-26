#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int pow(int x, int n, int d)
{
    if (d == 1)
        return 0;

    if (x == 0)
        return 0;

    ll ans = 1, y = x % d;

    while (n > 0)
    {
        if (n & 1) // odd
            ans = ((ans)*y) % d;

        y = (y * y) % d;

        if (y < 0)
            y += d;

        n = n >> 1; // n/2
    }

    if (ans < 0)
    {
        ans = (d - abs(ans) % d);
        return ans;
    }

    return ans;
}

int main()
{
    cout << pow(2, 6, 3);
    return 0;
}