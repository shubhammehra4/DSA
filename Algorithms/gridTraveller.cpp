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

    string key = to_string (m) + "," + to_string (n); // deniting a node as a key

    if (memo.find (key)->second) return memo[key];

    if (m == 1 && n == 1) return 1;

    memo.insert ({key, memoGridTraveller (m - 1, n) + memoGridTraveller (m, n - 1) });
    return memo[key];
}

ll dynamicGridTraveller (ll m, ll n)
{
    vector<vector<int>> paths (m, vector<int> (n, 0) );
    paths[0][n - 1] = 1; //starting

    for (int i = n - 2; i >= 0; i--)
        paths[0][i] = paths[0][i + 1]; // left side

    for (int i = 1; i < m; i++)
        paths[i][n - 1] = paths[i - 1][n - 1]; // top side

    for (int i = 1; i < m; i++)
    {
        for (int j = n - 2; j >= 0; j--)
            paths[i][j] = paths[i - 1][j] + paths[i][j + 1];
    }

    return paths[m - 1][0];
}

int main()
{
    cout << memoGridTraveller (1, 1) << endl;
    cout << memoGridTraveller (3, 2) << endl;
    cout << memoGridTraveller (18, 18) << endl;
    cout << dynamicGridTraveller (18, 18) << endl;
    cout << memoGridTraveller (15, 15) << endl;
    cout << gridTraveller (15, 15) << endl;
    cout << dynamicGridTraveller (15, 15) << endl;
    return 0;
}