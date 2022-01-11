#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(ll n)
{
    ll k1, k2, ktot, red;

    k1 = n * n;                  // number of ways to place first knight
    k2 = k1 - 1;                 // number of ways to place second knight
    ktot = k1 * k2 / 2;          // total number of ways to place 2 knights
    red = 4 * (n - 1) * (n - 2); // total number of attacked places to be reduced

    cout << ktot - red << endl;
}

int main()
{
    ll tc;
    cin >> tc;

    for (ll i = 1; i <= tc; i++)
        solve(i);

    return 0;
}
