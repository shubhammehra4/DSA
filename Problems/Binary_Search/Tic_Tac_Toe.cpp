#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
/*
Link : https://www.codechef.com/problems/TICTACTO
    Store all the moves played in order
    Binary Search 1 - N*M
    for every mid - create the state of the game at that point and check for existance of k*k sub-grid
    check will be done using prefix sum matrix

    if grid found store the ans=mid, then high = mid-1, else low = mid+1
    return ans
*/

int main()
{
    fast_cin();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int>> moves;
        forn(i, n * m)
        {
            int x, y;
            cin >> x >> y;
            moves.push_back({x, y});
        }

        ll low = 0, high = n * m - 1, ans = n * m;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;

            vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));

            forn(i, mid + 1)
            {
                if (i % 2 == 0)
                    a[moves[i].first][moves[i].second] = 1; // Alice
                else
                    a[moves[i].first][moves[i].second] = -1; // Bob
            }

            // Prefix Sum
            forsn(i, 1, n + 1)
            {
                forsn(j, 1, m + 1)
                {
                    a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
                }
            }

            bool found = false;

            forsn(i, k, n + 1)
            {
                forsn(j, k, m + 1)
                {
                    int cnt = a[i][j] - a[i][j - k] - a[i - k][j] + a[i - k][j - k];

                    if (abs(cnt) == k * k)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                    break;
            }

            if (found)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        if (ans == n * m)
            cout << "Draw" << ln;
        else if (ans % 2 == 0)
            cout << "Alice" << ln;
        else
            cout << "Bob" << ln;
    }
    return 0;
}