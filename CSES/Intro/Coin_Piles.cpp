#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll lPile, rPile;
    cin >> lPile >> rPile;

    if (lPile < rPile)
        swap(lPile, rPile);

    if (lPile > 2 * rPile)
        cout << "NO\n";
    else if ((lPile + rPile) % 3 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}