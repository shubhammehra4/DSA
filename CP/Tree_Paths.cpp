#include <bits/stdc++.h>
#define ll long long int
#define loop(a, b, i) for (long long int i = a; i < b; i++)
#define loopr(a, b, i) for (long long int i = a; i >= b; i--)
#define cn continue;
#define pb push_back
#define db double
#define mp make_pair
#define sz(x) (ll)((x).size())
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define f first
#define se second
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define all(x) x.begin(), x.end()
#define pi 3.14159265358979323846
#define quick                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll mod = 1000000007;
const ll MAX = 8000000000000000064LL;
const ll MIN = -8000000000000000064LL;
ll add(ll x, ll y)
{
    ll res = x + y;
    return (res >= mod ? res - mod : res);
}
ll mul(ll x, ll y)
{
    ll res = x * y;
    return (res >= mod ? res % mod : res);
}
ll sub(ll x, ll y)
{
    ll res = x - y;
    return (res < 0 ? res + mod : res);
}
ll power(ll x, ll y)
{
    ll res = 1;
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
ll mod_inv(ll x) { return power(x, mod - 2); }
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll x, ll y)
{
    ll res = x / gcd(x, y);
    return (res * y);
}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
using namespace std;

const ll dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
const ll dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

bool isprime(ll n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0 and n != 2)
        return false;
    for (ll i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

const int N = 1e5 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];

void dfs(int u, int p = 0)
{
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v : g[u])
        if (v != p)
        {
            dfs(v, u);
            sz[u] += sz[v];
        }
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int k = LG; k >= 0; k--)
        if (dep[par[u][k]] >= dep[v])
            u = par[u][k];
    if (u == v)
        return u;
    for (int k = LG; k >= 0; k--)
        if (par[u][k] != par[v][k])
            u = par[u][k], v = par[v][k];
    return par[u][0];
}

signed main()
{
    quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin>>tc;
    loop(0, tc, Q)
    {
        int n, q;
        cin >> n >> q;
        loop(0, n - 1, i)
        {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1);
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            int l = lca(a, b);
            if (l != 1)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }
    }

    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}