// Travel a Grid of mXn only going right or down from top-left to bottom-right
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll gridTraveller (int m , int n) // Time:O(2^(n+m)) Space: O(m+n)
{
    if (m == 0 || n == 0) return 0;

    if (m == 1 && n == 1) return 1;

    return gridTraveller (m - 1, n) + gridTraveller (m, n - 1);
}

map<string, ll> memo;
ll memoGridTraveller (ll m , ll n) // Time:O(m*n) Space: O(m+n)
{
    if (m == 0 || n == 0) return 0;

    string key = to_string (m) + "," + to_string (n);

    if (memo.find (key)->second) return memo[key];

    if (m == 1 && n == 1) return 1;

    memo.insert ({key, memoGridTraveller (m - 1, n) + memoGridTraveller (m, n - 1) });
    return memo[key];
}

int main()
{
    cout << memoGridTraveller (1, 1) << endl;
    cout << memoGridTraveller (2, 3) << endl;
    cout << memoGridTraveller (3, 2) << endl;
    cout << memoGridTraveller (3, 3) << endl;
    cout << memoGridTraveller (18, 18) << endl;
    cout << gridTraveller (15, 15) << endl;
    return 0;
}