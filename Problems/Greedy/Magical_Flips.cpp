#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<lli, lli> p64;
typedef vector<lli> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<lli>> vv64;
typedef vector<vector<p64>> vvp64;
#define forn(i, e) for (lli i = 0; i < e; i++)
#define forsn(i, s, e) for (lli i = s; i < e; i++)
#define rforn(i, s) for (lli i = s; i >= 0; i--)
#define rforsn(i, s, e) for (lli i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
lli MOD = 998244353;
double eps = 1e-12;
#define INF 2e18

int main()
{

    fast_cin();
    lli t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        v64 a(n), b(n);
        forn(i, n)
        {
            cin >> a[i];
        }
        forn(i, n)
        {
            cin >> b[i];
        }
        v32 state(n, -1);

        for (lli bit = 1 << 29; bit > 0; bit >>= 1)
        {
            bool poss = true;
            forn(i, n)
            {
                if (state[i] == 0 && !(a[i] & bit))
                    poss = false;
                else if (state[i] == 1 && !(b[i] & bit))
                    poss = false;
                else if (!(a[i] & bit) and !(b[i] & bit))
                    poss = false;
            }
            if (!poss)
                continue;

            forn(i, n)
            {
                if (state[i] != -1)
                    continue;
                if (!(a[i] & bit))
                    state[i] = 1;
                else if (!(b[i] & bit))
                    state[i] = 0;
            }
        }

        lli ans = (1 << 30) - 1, flips = 0;

        forn(i, n)
        {
            if (state[i] == 1)
            {
                flips++;
                ans &= b[i];
            }
            else
                ans &= a[i];
        }

        cout << ans << " " << flips << ln;
    }
    return 0;
}