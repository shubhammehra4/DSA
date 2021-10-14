#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long int
#define ul unsigned long long
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;
const int dif = LLONG_MIN;
#define vt vector
#define vi vector<int>
#define loop(i, a, b) for (int i = a; i < b; ++i)
int power(int x, int y)
{
    int res = 1;
    x %= mod;
    while (y)
    {
        if (y & 1)
            res = mul(res, x);
        y >>= 1;
        x = mul(x, x);
    }
    return res;
}
int mul(int x, int y)
{
    int res = x * y;
    return (res >= mod ? res % mod : res);
}
int mod_inv(int x)
{
    return power(x, mod - 2);
}

const int N = 4e5;
vi fact(N + 1);

void init()
{
    fact[0] = 1;
    loop(i, 1, N + 1) fact[i] = mul(fact[i - 1], i);
}

int nCr(int n, int r)
{
    int ans = fact[n];
    ans *= mod_inv(fact[n - r]);
    ans %= mod;
    ans *= mod_inv(fact[r]);
    ans %= mod;
    return ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    init();
    int tc = 1;
    cin >> tc;
    loop(Q, 0, tc)
    {
        int n;
        cin >> n;
        int ans = nCr(2 * n, n);
        ans *= mod_inv(n + 1);
        ans %= mod;
        cout << ans << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}