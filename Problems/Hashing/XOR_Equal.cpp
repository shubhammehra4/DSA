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
        lli n, x;
        cin >> n >> x;
        v64 arr(n);
        unordered_map<lli, lli> cnt, opCnt;
        for (auto &i : arr)
        {
            cin >> i;
            cnt[i]++;
            opCnt[i] = 0;
        }

        int xorVal;
        for (int i : arr)
        {
            if (x == 0)
                break;
            xorVal = i ^ x;
            // dbg(xorVal);
            cnt[xorVal]++;
            opCnt[xorVal]++;
        }

        v64 maxList;
        lli maxVal = -1;

        for (auto e : cnt)
        {
            if (maxVal < e.second)
            {
                maxVal = e.second;
                maxList.clear();
                maxList.pb(e.first);
            }
            else if (maxVal == e.second)
                maxList.pb(e.first);
        }

        lli minOp = INT_MAX;

        for (auto i : maxList)
            minOp = min(minOp, opCnt.at(i));

        cout << maxVal << " " << minOp << ln;
    }
    return 0;
}