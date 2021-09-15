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
        lli n, k, x;
        cin >> n >> k >> x;
        v64 cost(n);

        forn(i, n)
        {
            cin >> cost[i];
        }
        sort(all(cost));
        lli ans = 0, sum;
        lli j = cost.size();

        while (k > 0 && j > 1)
        {
            sum = cost[j - 1] + cost[j - 2];

            if (x <= sum)
            {
                j -= 2;
                ans += x;
                k--;
            }
            else
                break;
        }

        ans += accumulate(cost.begin(), cost.begin() + j, 0ll);

        cout << ans << ln;
    }
    return 0;
}