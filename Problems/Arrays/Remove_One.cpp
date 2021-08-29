#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define forn(i, e) for (lli i = 0; i < e; i++)
#define forsn(i, s, e) for (lli i = s; i < e; i++)
#define rforn(i, s) for (lli i = s; i >= 0; i--)
#define rforsn(i, s, e) for (lli i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main()
{

    fast_cin();
    lli t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<lli> a, b;
        unordered_set<int> s;
        lli x;

        forn(i, n)
        {
            cin >> x;
            a.pb(x);
            s.insert(x);
        }

        forn(i, n - 1)
        {
            cin >> x;
            b.pb(x);
        }

        sort(all(a));
        sort(all(b));
        lli ans = b[0] - a[1];

        for (auto i : b)
        {
            if (s.count(i - ans) == 0)
            {
                ans = b[0] - a[0];
                break;
            }
        }
        if (ans <= 0)
            ans = b[0] - a[0];

        cout << ans << ln;
    }
    return 0;
}